#include "TemplateMethodPattern.h"

#include <iostream>
#include <format>

namespace TemplateMethodPattern
{
	Game::Game(int number_of_players)
	: current_player(0)
	, number_of_players(number_of_players)
	{

	}

	void Game::run()
	{
		start();
		while (!have_winner())
		{
			take_turn();
		}
		std::cout << "Player " << get_winner() << " wins.\n";
	}

	Chess::Chess()
	: Game(2)
	, turns(0)
	, max_turns(10)
	{
	}

	void Chess::start()
	{
		std::cout << "Starting a game of chess with " << number_of_players
			<< " players\n";
	}

	bool Chess::have_winner()
	{
		return turns == max_turns;
	}

	void Chess::take_turn()
	{
		std::cout << "Turn " << turns << " taken by player " << 
			current_player << "\n";
		turns++;
		current_player = (current_player + 1) % number_of_players;
	}

	int Chess::get_winner()
	{
		return current_player;
	}

	void TemplateMethodPattern::Run()
	{
		Chess chess;
		chess.run();
	}
};
