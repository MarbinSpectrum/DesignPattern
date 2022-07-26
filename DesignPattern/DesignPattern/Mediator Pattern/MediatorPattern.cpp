#include "MediatorPattern.h"
#include <iostream>
#include <format>

namespace MediatorPattern
{
	Person::Person(const std::string& name)
	: name(name)
	, room(NULL)
	{
	}

	void Person::Receive(const std::string& origin, const std::string& message)
	{
		std::string s = std::format("{0}: \"{1}\"", origin, message);
		std::cout << std::format("[{0} 's chat session] {1}", name, s) << "\n";
		chat_log.emplace_back(s);
	}

	void Person::Say(const std::string& message) const
	{
		room->BroadCast(name, message);
	}

	void Person::Pm(const std::string& who, const std::string& message) const
	{
		room->Message(name, who, message);
	}

	void ChatRoom::Join(Person* p)
	{
		std::string join_msg = std::format("{} joins the chat", p->name);
		BroadCast("Room", join_msg);
		p->room = this;
		people.insert({ p->name,p });
	}

	void ChatRoom::BroadCast(const std::string& origin, const std::string& message)
	{
		for (auto p : people)
		{
			const std::string& name = p.first;
			Person* person = p.second;

			if (name != origin)
			{
				person->Receive(origin, message);
			}
		}
	}

	void ChatRoom::Message(const std::string& origin, const std::string& who, const std::string& message)
	{
		if (people.find(who) != people.end())
		{
			people[who]->Receive(origin, message);
		}
	}

	void MediatorPattern::Run()
	{
		ChatRoom room;

		Person john("john");
		Person jane("jane");
		room.Join(&john);
		room.Join(&jane);
		john.Say("hi room");
		jane.Say("oh, hey john");

		Person simon("simon");
		room.Join(&simon);
		simon.Say("hi everyone!");

		jane.Pm("simon", "glad you could join us, simon");
	}
};
