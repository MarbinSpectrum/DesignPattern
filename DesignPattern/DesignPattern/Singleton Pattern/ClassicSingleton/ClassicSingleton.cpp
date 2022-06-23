#include "ClassicSingleton.h"
#include <iostream>

namespace ClassicSingleton
{
	Database::Database()
	{
	}

	Database& Database::GetInstance()
	{
		//Database�� ���α׷��� ����ɶ����� ����־� �Ҹ��� ȣ���� �ʿ����.
		
		//����ƽ ������ �ʱ�ȭ�� ��Ÿ�� �߿� �� �ѹ��� ����Ǳ� ������
		//�޸� ������ �߻����� �ʴ´�.
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