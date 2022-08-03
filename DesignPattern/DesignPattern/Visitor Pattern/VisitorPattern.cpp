#include "VisitorPattern.h"
#include "../StudyUtility.h"

#include <iostream>
#include <format>

namespace VisitorPattern
{
    DoubleExpression::DoubleExpression(const double value)
    : value(value)
    {
    }

    void DoubleExpression::accept(ExpressionVisitor* visitor)
    {
        visitor->visit(this);
    }

    AdditionExpression::AdditionExpression(Expression* const left, Expression* const right)
    : left(left)
    , right(right)
    {
    }

    AdditionExpression::~AdditionExpression()
    {
        SAFE_DELETE(left);
        SAFE_DELETE(right);
    }

    MutupleExpression::MutupleExpression(Expression* const left, Expression* const right)
    : left(left)
    , right(right)
    {

    }

    MutupleExpression::~MutupleExpression()
    {
        SAFE_DELETE(left);
        SAFE_DELETE(right);
    }

    void MutupleExpression::accept(ExpressionVisitor* visitor)
    {
        visitor->visit(this);
    }

    void AdditionExpression::accept(ExpressionVisitor* visitor)
    {
        visitor->visit(this);
    }

    void ExpressionPrinter::visit(DoubleExpression* de)
    {
        oss << de->value;
    }

    void ExpressionPrinter::visit(AdditionExpression* ae)
    {
        oss << "(";
        ae->left->accept(this);
        oss << "+";
        ae->right->accept(this);
        oss << ")";
    }

    void ExpressionPrinter::visit(MutupleExpression* me)
    {
        oss << "(";
        me->left->accept(this);
        oss << "*";
        me->right->accept(this);
        oss << ")";
    }

    std::string ExpressionPrinter::str()
    {
        return oss.str();
    }

    void ExpressionEvaluator::visit(DoubleExpression* de)
    {
        result = de->value;
    }
    void ExpressionEvaluator::visit(AdditionExpression* ae)
    {
        ae->left->accept(this);
        auto temp = result;
        ae->right->accept(this);
        result += temp;
    }
    void ExpressionEvaluator::visit(MutupleExpression* me)
    {
        me->left->accept(this);
        auto temp = result;
        me->right->accept(this);
        result *= temp;
    }


    void VisitorPattern::Run()
    {
        auto e = new AdditionExpression
        {
            new DoubleExpression{1},
            new MutupleExpression
            {
                new DoubleExpression{2},
                new DoubleExpression{3}
            }
        };
        ExpressionPrinter printer;
        ExpressionEvaluator evaluator;
        printer.visit(e);
        evaluator.visit(e);
        std::cout << printer.str() << " = " << evaluator.result << "\n";
    }
};
