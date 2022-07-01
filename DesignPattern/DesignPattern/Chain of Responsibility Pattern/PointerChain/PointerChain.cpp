#include "PointerChain.h"

#include <iostream>
#include <format>

namespace PointerChain
{
	CreatureModifier::CreatureModifier()
	: next(NULL)
	{

	}

	void CreatureModifier::add(CreatureModifier* cm)
	{
		if (next != NULL)
		{
			next->add(cm);
		}
		else
		{
			next = cm;
		}
	}

	void CreatureModifier::handle(Creature* creature)
	{
		if (next != NULL)
		{
			next->handle(creature);
		}
	}

	DoubleAttackModifier::DoubleAttackModifier()
	: CreatureModifier()
	{
	}

	void DoubleAttackModifier::handle(Creature* creature)
	{
		creature->attack *= 2;
		CreatureModifier::handle(creature);
	}

	IncreaseDefenseModifier::IncreaseDefenseModifier()
	: CreatureModifier()
	{
	}

	void IncreaseDefenseModifier::handle(Creature* creature)
	{
		if (creature->attack <= 2)
			creature->defense += 1;
		CreatureModifier::handle(creature);
	}

	void PointerChain::Run()
	{
		Creature* goblin = new Creature{"Goblin",1,1 };
		CreatureModifier root;
		DoubleAttackModifier r1;
		DoubleAttackModifier r2;
		IncreaseDefenseModifier r3;

		root.add(&r1);
		root.add(&r2);
		root.add(&r3);

		root.handle(goblin);

		std::cout << std::format("name:{0}  attack:{1}  defense:{2}",
			goblin->name, goblin->attack, goblin->defense) << std::endl;
	}
}