#include "FunctionalDecorator.h"
#include <format>
#include <iostream>

namespace FunctionalDecorator
{
	template<typename Func>
	Logger<Func>::Logger(const Func& func, const std::string name)
	: func(func)
	, name(name)
	{
	}

	template<typename Func>
	void Logger<Func>::operator()() const
	{
		std::cout << std::format("Start {}", name) << std::endl;
		func();
		std::cout << std::format("End {}", name) << std::endl;
	}

	void FunctionalDecorator::Run()
	{
		auto call = Logger([]() {std::cout << "Hello!!" << std::endl; }, "FD");
		call();
	}
};
