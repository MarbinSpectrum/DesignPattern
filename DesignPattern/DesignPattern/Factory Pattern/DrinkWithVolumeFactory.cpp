#include "DrinkWithVolumeFactory.h"
#include "Tea.h"
#include "Coffee.h"

DrinkWithVolumeFactory::DrinkWithVolumeFactory()
{
	factories["tea"] = []
	{
		auto tea = std::make_unique<Tea>();
		tea->prepare(200);
		return tea;
	};

	factories["coffee"] = []
	{
		auto coffee = std::make_unique<Coffee>();
		coffee->prepare(50);
		return coffee;
	};
}

inline std::unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(const std::string& name)
{
	return factories[name]();
}
