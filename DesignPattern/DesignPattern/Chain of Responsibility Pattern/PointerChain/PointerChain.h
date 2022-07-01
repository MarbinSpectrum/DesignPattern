#pragma once

#include <string>

namespace PointerChain
{
	struct Creature
	{
		std::string name;
		int attack;
		int defense;
	};

	class CreatureModifier
	{
		CreatureModifier* next;
	public:
		explicit CreatureModifier();
		void add(CreatureModifier* cm);
		virtual void handle(Creature* creature);
	};

	class DoubleAttackModifier : public CreatureModifier
	{
	public:
		explicit DoubleAttackModifier();
		virtual void handle(Creature* creature) override;
	};

	class IncreaseDefenseModifier : public CreatureModifier
	{
	public:
		explicit IncreaseDefenseModifier();
		virtual void handle(Creature* creature) override;
	};

	struct PointerChain
	{
		static void Run();
	};
};