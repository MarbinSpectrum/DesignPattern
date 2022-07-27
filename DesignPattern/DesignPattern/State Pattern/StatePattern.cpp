#include "StatePattern.h"

#include <iostream>
#include <format>

namespace StatePattern
{
	LightSwitch::LightSwitch()
	: state(new OffState())
	{
	}

	void LightSwitch::set_state(State* state)
	{
		this->state = state;
	}

	void LightSwitch::on()
	{
		state->on(this);
	}

	void LightSwitch::off()
	{
		state->off(this);
	}

	void State::on(LightSwitch* ls)
	{
		std::cout << "Light is already on" << "\n";
	}

	void State::off(LightSwitch* ls)
	{
		std::cout << "Light is already off" << "\n";
	}

	OnState::OnState()
	{
		std::cout << "Light turned on" << "\n";
	}

	void OnState::off(LightSwitch* ls)
	{
		std::cout << "Switching light off..." << "\n";
		ls->set_state(new OffState());
		delete this;
	}

	OffState::OffState()
	{
		std::cout << "Light turned off" << "\n";
	}

	void OffState::on(LightSwitch* ls)
	{
		std::cout << "Switching light on..." << "\n";
		ls->set_state(new OnState());
		delete this;
	}

	void StatePattern::Run()
	{
		LightSwitch ls;
		ls.on();
		ls.off();
		ls.off();
	}
};
