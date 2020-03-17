#pragma once

class Singleton
{
protected :
	static Singleton *instance;
public:
	static Singleton *Get();
public:
	void Init();
protected:
	Singleton();
};

#define SINGLETON Singleton::Get()
