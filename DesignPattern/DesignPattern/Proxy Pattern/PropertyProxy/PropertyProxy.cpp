#include "PropertyProxy.h"

namespace PropertyProxy
{
	template<typename T>
	Property<T>::Property(const T initial_value)
	{
		*this = initial_value;
	}

	template<typename T>
	Property<T>::operator T()
	{
		//get �۾� ����
		return value;
	}

	template<typename T>
	T Property<T>::operator=(T new_value)
	{
		//set �۾� ����
		return value = new_value;
	}

	void PropertyProxy::Run()
	{
		Creature creature;
		creature.agility = 20;
		auto x = creature.strength;
	}
};
