#pragma once

namespace StatePattern
{
	struct State;
	struct OffState;
	struct OnState;

	class LightSwitch
	{
		State* state;
	public:
		LightSwitch();
		void set_state(State* state);
		void on();
		void off();
	};

	struct State
	{
		virtual void on(LightSwitch* ls);
		virtual void off(LightSwitch* ls);
	};

	struct OnState : State
	{
		OnState();
		void off(LightSwitch* ls) override;
	};

	struct OffState : State
	{
		OffState();
		void on(LightSwitch* ls) override;
	};

	struct StatePattern
	{
		static void Run();
	};
}
