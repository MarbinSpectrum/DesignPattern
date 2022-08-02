#pragma once

namespace TemplateMethodPattern
{
	class Game
	{
	public:
		explicit Game(int number_of_players);
		void run();
	protected:
		int current_player;
		int number_of_players;
		virtual void start() = 0;
		virtual bool have_winner() = 0;
		virtual void take_turn() = 0;
		virtual int get_winner() = 0;
	};

	class Chess : public Game
	{
	public:
		explicit Chess();
	protected:
		virtual void start() override;
		virtual bool have_winner() override;
		virtual void take_turn() override;
		virtual int get_winner() override;
	private:
		int turns;
		int max_turns;
	};

	struct TemplateMethodPattern
	{
		static void Run();
	};
}
