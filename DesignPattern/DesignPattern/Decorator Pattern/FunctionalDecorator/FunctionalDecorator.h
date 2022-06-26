#pragma once

#include <string>
#include <functional>


namespace FunctionalDecorator
{
	template<typename Func>
	struct Logger
	{
		Func func;
		std::string name;

		Logger(const Func& func, const std::string name);
		void operator()() const;
	};

	struct FunctionalDecorator
	{
		static void Run();
	};
}
