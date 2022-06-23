#include "ClassicSingleton.h"
#include <iostream>

namespace ClassicSingleton
{
	Database::Database()
	{
	}

	Database& Database::GetInstance()
	{
		//Database가 프로그램이 종료될때까지 살아있어 소멸자 호출이 필요없다.
		
		//스태틱 변수의 초기화는 런타임 중에 단 한번만 수행되기 때문에
		//메모리 누수가 발생되지 않는다.
		static Database* instance = new Database();
		return *instance;
	}

	void Database::Add(const int n)
	{
		list.push_back(n);
	}

	void Database::Print()
	{
		for (int n : list)
		{
			std::cout << n << std::endl;
		}
	}
}