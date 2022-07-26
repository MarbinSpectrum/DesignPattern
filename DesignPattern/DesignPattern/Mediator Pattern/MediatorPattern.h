#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace MediatorPattern
{
	struct ChatRoom;
	struct Person;

	struct Person
	{
		std::string name;
		ChatRoom* room;
		std::vector<std::string> chat_log;

		Person(const std::string& name);

		void	  Receive(const std::string& origin, const std::string& message);
		void		  Say(const std::string& message) const;
		void		   Pm(const std::string& who, const std::string& message) const;
	};

	struct ChatRoom
	{
		typedef std::unordered_map<std::string, Person*> PersonMap;
		PersonMap people;

		void		 Join(Person* p);
		void	BroadCast(const std::string& origin, const std::string& message);
		void	  Message(const std::string& origin, const std::string& who,
						  const std::string& message);
	};

	struct MediatorPattern
	{
		static void		Run();
	};
}
