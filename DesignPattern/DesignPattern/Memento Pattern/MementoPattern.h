#pragma once

namespace MementoPattern
{
	class Memento;
	class BankAccount;

	class BankAccount
	{
		Memento* now;
		int historyLen;

	public:
		explicit	BankAccount(const int balance);
		void		Deposit(const int amount);
		void		Restore(const int state);
		void		Undo();
		void		Redo();
		void		Print();
	};

	class Memento
	{
		int balance;
		int num;
		Memento* next;
		Memento* back;

	public:
		Memento(const int balance, const int now);
		~Memento();
		friend class BankAccount;
	};

	class MementoPattern
	{
	public:
		static void Run();
	};
}
