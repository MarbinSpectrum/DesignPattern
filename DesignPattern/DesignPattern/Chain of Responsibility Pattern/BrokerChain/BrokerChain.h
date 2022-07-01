#pragma once

#include <string>
#include <boost/signals2/signal.hpp>

namespace BrokerChain
{
	struct Query
	{
		std::string creature_name;
		enum Argument
		{
			attack,
			defense
		};
		Argument argument;
		int result;
	};

	struct Game
	{
		boost::signals2::signal<void(Query&)> queries;
	};

	class Creature
	{
	private:
		Game* game;
		int attack;
		int defense;
	public:
		std::string name;
		Creature(Game* game, const std::string& name,const int attack,const int defense);
		int get_attack() const;
		int get_defense() const;
	};

	class CreatureModifier
	{
	private:
		Game* game;

	public:
		CreatureModifier(Game* game);
	};

	class DoubleAttackModifier: public CreatureModifier
	{
		boost::signals2::connection conn;
	public:
		DoubleAttackModifier(Game* game);
		~DoubleAttackModifier();
	};

	struct BrokerChain
	{
		static void Run();
	};
};