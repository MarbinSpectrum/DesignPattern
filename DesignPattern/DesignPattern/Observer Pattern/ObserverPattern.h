#pragma once

#include <string>
#include <set>

namespace ObserverPattern
{
	struct Person;

	template<typename T>
	struct Observer
	{
		virtual void field_changed(T& source, 
			const std::string& field_name) = 0;
	};

	struct ConsoleObserver : Observer<Person>
	{
		virtual void field_changed(Person& source,
			const std::string& field_name) override;
	};

	template<typename T>
	struct Observable
	{
		void notify(T& source, const std::string name);
		void subscribe(Observer<T>* f);
		void unsubscribe(Observer<T>* f);
	private:
		std::set<Observer<T>*> observers;
	};

	struct Person : Observable<Person>
	{
		Person(const int age);
		int get_age() const;
		void set_age(const int value);

	private:
		int age;
	};

	struct ObserverPattern
	{
		static void Run();
	};
}
