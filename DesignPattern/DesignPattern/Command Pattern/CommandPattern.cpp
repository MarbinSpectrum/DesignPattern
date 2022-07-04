#include "CommandPattern.h"

namespace CommandPattern
{
	BankAccount::BankAccount()
		: balance(0)
		, overdraft_limit(-500)
	{
	}

	void BankAccount::deposit(int amount)
	{
		balance += amount;
	}

	bool BankAccount::withdraw(int amount)
	{
		if (balance - amount >= overdraft_limit)
		{
			balance -= amount;
			return true;
		}
		return false;
	}

	BackAccountCommand::BackAccountCommand(BankAccount* account, const Action action, const int amount)
		: account(account)
		, action(action)
		, amount(amount)
	{
	}

	void BackAccountCommand::call()
	{
		switch (action)
		{
		case deposit:
			account->deposit(amount);
			break;
		case withdraw:
			succeeded = account->withdraw(amount);
			break;
		}
	}

	void BackAccountCommand::undo()
	{
		switch (action)
		{
		case deposit:
			account->withdraw(amount);
			break;
		case withdraw:
			if (succeeded)
			{
				account->deposit(amount);
				succeeded = false;
			}
			break;
		}
	}

	CompositeBankAccountCommand::CompositeBankAccountCommand(const std::initializer_list<value_type>& items)
		: std::vector<BackAccountCommand>(items)
	{
	}

	void CompositeBankAccountCommand::call()
	{
		bool ok = true;
		for (auto& cmd : *this)
		{
			cmd.call();
		}
	}

	void CompositeBankAccountCommand::undo()
	{
		for (auto it = rbegin(); it != rend(); it++)
		{
			it->undo();
		}
	}

	MoneyTransferCommand::MoneyTransferCommand(BankAccount* from, BankAccount* to, int amount)
	: CompositeBankAccountCommand({ BackAccountCommand(from, BackAccountCommand::Action::withdraw, amount),
									BackAccountCommand(to, BackAccountCommand::Action::deposit, amount) })
	{
	}
}