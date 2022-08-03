#pragma once

#include <sstream>

namespace VisitorPattern
{
	struct ExpressionVisitor;

	struct Expression
	{
		virtual void accept(ExpressionVisitor* visitor) = 0;
	};
	struct DoubleExpression : Expression
	{
		double value;
		explicit DoubleExpression(const double value);
		virtual void accept(ExpressionVisitor* visitor) override;
	};
	struct AdditionExpression : Expression
	{
		Expression* left;
		Expression* right;

		AdditionExpression(Expression* const left, Expression* const right);
		~AdditionExpression();

		virtual void accept(ExpressionVisitor* visitor) override;
	};
	struct MutupleExpression : Expression
	{
		Expression* left;
		Expression* right;

		MutupleExpression(Expression* const left, Expression* const right);
		~MutupleExpression();

		virtual void accept(ExpressionVisitor* visitor) override;
	};

	struct ExpressionVisitor
	{
		virtual void visit(DoubleExpression* de) = 0;
		virtual void visit(AdditionExpression* ae) = 0;
		virtual void visit(MutupleExpression* me) = 0;
	};
	struct ExpressionPrinter : ExpressionVisitor
	{
		virtual void visit(DoubleExpression* de) override;
		virtual void visit(AdditionExpression* ae) override;
		virtual void visit(MutupleExpression* me) override;
		std::string str();
	private:
		std::ostringstream oss;
	};
	struct ExpressionEvaluator : ExpressionVisitor
	{
		double result;
		virtual void visit(DoubleExpression* de) override;
		virtual void visit(AdditionExpression* ae) override;
		virtual void visit(MutupleExpression* me) override;
	};

	struct VisitorPattern
	{
		static void Run();
	};
}
