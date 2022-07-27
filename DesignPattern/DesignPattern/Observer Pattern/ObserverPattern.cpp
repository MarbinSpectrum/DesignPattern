#include "ObserverPattern.h"

#include <iostream>
#include <format>

namespace ObserverPattern
{
	Person::Person(const int age)
	: age(age)
	{
	}

	int Person::get_age() const
	{
		return age;
	}

	void Person::set_age(const int value)
	{
		if (this->age == value)
			return;

		this->age = value;

		//�����ڿ��� ���� �ٲ������ �˷��ش�.
		notify(*this, "age");
	}

	void ConsoleObserver::field_changed(Person& source, const std::string& field_name)
	{
		std::cout << std::format("Person's {0} has changed to {1}", 
			field_name, source.get_age()) << "\n";
	}

	template<typename T>
	void Observable<T>::notify(T& source, const std::string name)
	{
		for (auto obs : observers)
		{
			//�����ڵ鿡�� ��ȭ����� ����
			obs->field_changed(source, name);
		}
	}

	template<typename T>
	void Observable<T>::subscribe(Observer<T>* f)
	{
		//������ ���
		observers.insert(f);
	}

	template<typename T>
	void Observable<T>::unsubscribe(Observer<T>* f)
	{
		//������ ����
		observers.erase(f);
	}

	void ObserverPattern::Run()
	{
		Person p(20);
		ConsoleObserver ob;
		p.subscribe(&ob);
		p.set_age(21);
		p.set_age(22);
	}
};
