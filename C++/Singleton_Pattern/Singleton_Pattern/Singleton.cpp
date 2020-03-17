#include "Singleton.h"

Singleton * Singleton::instance = nullptr;

Singleton * Singleton::Get()
{
	if (instance == nullptr)
		instance = new Singleton;
	return instance;
}

void Singleton::Init()
{
}

Singleton::Singleton()
{
}