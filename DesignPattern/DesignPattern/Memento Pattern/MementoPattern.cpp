#include "MementoPattern.h"

#include <iostream>
#include <format>

namespace MementoPattern
{
	BankAccount::BankAccount(const int balance)
	: now(new Memento(balance, 0))
	{
		
	}

	void BankAccount::Deposit(const int amount)
	{
		if (now->next != NULL)
		{
			delete now->next;
			now->next = NULL;
		}

		historyLen = now->num + 1;
		now->next = new Memento(now->balance + amount, now->num + 1);
		now->next->back = now;
		now = now->next;
	}

	void BankAccount::Restore(const int state)
	{
		if (state > historyLen || state < 0)
			return;


		while (now->num > state)
		{
			now = now->back;
		}

		while (now->num < state)
		{
			now = now->next;
		}
	}

	void BankAccount::Undo()
	{
		if(now->back != NULL)
			now = now->back;
	}

	void BankAccount::Redo()
	{
		if (now->next != NULL)
			now = now->next;
	}

	void BankAccount::Print()
	{
		std::cout << now->balance << "\n";
	}

	Memento::Memento(const int balance, const int num)
	: balance(balance)
	, num(num)
	, next(NULL)
	, back(NULL)
	{

	}

	Memento::~Memento()
	{
		if (next != NULL)
		{
			delete next;
			next = NULL;
		}
	}

	void MementoPattern::Run()
	{
		BankAccount ba(100);
		ba.Deposit(50);
		ba.Print();

		ba.Deposit(25);
		ba.Print();

		ba.Undo();
		ba.Print();

		ba.Undo();
		ba.Print();

		ba.Redo();
		ba.Print();

		ba.Undo();
		ba.Print();

		ba.Restore(2);
		ba.Print();
	}
};
