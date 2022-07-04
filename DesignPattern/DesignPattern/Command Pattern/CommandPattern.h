#pragma once

#include <vector>
#include <initializer_list>

namespace CommandPattern
{
	class BankAccount
	{
	private:
		int balance;
		int overdraft_limit;

	public:
		BankAccount();
		void deposit(int amount);
		bool withdraw(int amount);
	};

	class Command
	{
	public:
		virtual void call() = 0;
		virtual void undo() = 0;
		bool succeeded = true;
	};

	class BackAccountCommand : public Command
	{
	public:
		BankAccount* account;
		enum Action
		{
			deposit,
			withdraw
		};
		Action action;
		int amount;

		BackAccountCommand(BankAccount* account, const Action action, const int amount);
		virtual void call() override;
		virtual void undo() override;
	};

	class CompositeBankAccountCommand : public std::vector<BackAccountCommand>, public Command
	{
	public:
		CompositeBankAccountCommand(const std::initializer_list<value_type>& items);
		virtual void call() override;
		virtual void undo() override;
	};

	class MoneyTransferCommand : public CompositeBankAccountCommand
	{
		MoneyTransferCommand(BankAccount* from, BankAccount* to, int amount);
	};
}