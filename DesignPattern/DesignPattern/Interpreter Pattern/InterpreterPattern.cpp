#include "InterpreterPattern.h"
#include <boost/lexical_cast.hpp>

namespace InterpreterPattern
{
	Token::Token(Type type, const std::string& text)
	: type(type)
	, text(text)
	{
	}

	std::ostream& operator<<(std::ostream& os, const Token& obj)
	{
		return os << "`" << obj.text << "`";
	}

	std::vector<Token> lex(const std::string& input)
	{
		std::vector<Token> result;

		for (int i = 0; i < input.size(); i++)
		{
			switch (input[i])
			{
			case '+':
				result.push_back(Token(Token::Type::plus, "+"));
				break;
			case '-':
				result.push_back(Token(Token::Type::minus, "-"));
				break;
			case '(':
				result.push_back(Token(Token::Type::lparen, "-"));
				break;
			case ')':
				result.push_back(Token(Token::Type::rparen, "-"));
				break;
			default:
			{
				std::string buffer = "";
				for (int j = i; j < input.size(); j++)
				{
					if ('0' <= input[j] && input[j] <= '9')
					{
						buffer += input[j];
					}
					else
					{
						i = j - 1;
						break;
					}
				}

				if (buffer.size() > 0)
				{
					result.push_back(Token(Token::Type::integer, buffer));
				}
			}
			break;
			}
		}
		return result;
	}


	Integer::Integer(const int value)
	: value(value)
	{
	}

	int Integer::eval() const
	{
		return value;
	}


	int BinaryOperation::eval() const
	{
		switch (type)
		{
		case BinaryOperation::addition:
			return lhs->eval() + rhs->eval();
		case BinaryOperation::subtraction:
			return lhs->eval() - rhs->eval();
		default:
			return 0;
		}
	}

	std::shared_ptr<Element> parse(const std::vector<Token>& tokens)
	{
		auto result = std::make_unique<BinaryOperation>();
		bool have_lhs = false;
		for (int i = 0; i < tokens.size(); i++)
		{
			auto token = tokens[i];
			switch (token.type)
			{
			case Token::Type::integer:
			{
				int value = boost::lexical_cast<int>(token.text);
				auto integer = std::make_shared<Integer>(value);
				if (have_lhs == false)
				{
					result->lhs = integer;
					have_lhs = true;
				}
				else
				{
					result->rhs = integer;
				}
			}
			break;
			case Token::Type::plus:
			{
				result->type = BinaryOperation::addition;
			}
			break;
			case Token::Type::minus:
			{
				result->type = BinaryOperation::subtraction;
			}
			break;
			case Token::Type::lparen:
			{
				int j = i;
				for (; j < tokens.size(); j++)
					if (tokens[j].type == Token::Type::rparen)
						break;

				std::vector<Token> subexpression(&tokens[i + 1], &tokens[j]);
				auto element = parse(subexpression);
				if (!have_lhs)
				{
					result->lhs = element;
					have_lhs = true;
				}
				else
					result->rhs = element;
				i = j;
				
			}
			break;
			}
		}
		return result;
	}

	void InterpreterPattern::Run()
	{
		std::string input = "(13+4)-(12+1)";
		auto tokens = lex(input);
		auto parsed = parse(tokens);
		std::cout << parsed->eval() << std::endl;
	}
};
