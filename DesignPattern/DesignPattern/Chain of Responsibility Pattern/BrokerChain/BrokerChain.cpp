#include "BrokerChain.h"

#include <iostream>
#include <format>

namespace BrokerChain
{
	Creature::Creature(Game* game, const std::string& name, const int attack, const int defense)
	: game(game)
	, name(name)
	, attack(attack)
	, defense(defense)
	{
	}

	int Creature::get_attack() const
	{
		Query q{ name, Query::Argument::attack, attack };
		game->queries(q);
		return q.result;
	}

	int Creature::get_defense() const
	{
		Query q{ name, Query::Argument::defense, defense };
		game->queries(q);
		return q.result;
	}

	CreatureModifier::CreatureModifier(Game* game)
	: game(game)
	{
	}

	DoubleAttackModifier::DoubleAttackModifier(Game* game)
	: CreatureModifier(game)
	{
		conn = game->queries.connect([&](Query& q)
		{
			if (q.argument == Query::Argument::attack)
			{
				q.result *= 2;
			}
		});
	}

	DoubleAttackModifier::~DoubleAttackModifier()
	{
		conn.disconnect();
	}

	void BrokerChain::Run()
	{
		//game이라는 브로커 객체를 통해서 값의 처리가 일어난다.
		Game* game = new Game;
		Creature goblin{ game ,"Strong Goblin",2,2 };
		std::cout << std::format("name:{0}  attack:{1}  defense:{2}",
			goblin.name, goblin.get_attack(), goblin.get_defense()) << std::endl;
		{
			DoubleAttackModifier dam(game);
			std::cout << std::format("name:{0}  attack:{1}  defense:{2}",
				goblin.name, goblin.get_attack(), goblin.get_defense()) << std::endl;
		}
		std::cout << std::format("name:{0}  attack:{1}  defense:{2}",
			goblin.name, goblin.get_attack(), goblin.get_defense()) << std::endl;
	}
}