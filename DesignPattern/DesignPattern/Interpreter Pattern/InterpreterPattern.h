#pragma once

#include <string>
#include <iostream>
#include <vector>

namespace InterpreterPattern
{
	struct Token
	{
		enum Type
		{
			integer,
			plus,
			minus,
			lparen,
			rparen
		};
		Type type;
		std::string text;

		explicit Token(Type type, const std::string& text);

		friend std::ostream& operator<<(std::ostream& os, const Token& obj);
	};

	std::vector<Token> lex(const std::string& input);

	class Element
	{
	public:
		virtual int eval() const = 0;
	};

	class Integer : public Element
	{
	public:
		int value;

		explicit Integer(const int value);
		int eval() const override;
	};

	class BinaryOperation : public Element
	{
	public:
		enum Type
		{
			addition,
			subtraction
		};
		Type type;
		std::shared_ptr<Element> lhs, rhs;

		int eval() const override;
	};

	std::shared_ptr<Element> parse(const std::vector<Token>& tokens);

	class InterpreterPattern
	{
	public:
		static void Run();
	};
}
