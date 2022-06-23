#pragma once

#include <vector>

namespace ClassicSingleton
{
	struct Database
	{
	protected:
		Database();

	public:
		static Database& GetInstance();
		Database(Database const&) = delete;
		Database(Database &&) = delete;
		Database& operator=(Database const&) = delete;
		Database& operator=(Database &&) = delete;

		void Add(const int n);
		void Print();

	public:
		std::vector<int> list;
	};
}