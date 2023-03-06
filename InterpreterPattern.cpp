#include"InterpreterPattern.h"

using namespace std;

class Expression {
public:
    virtual int evaluate() = 0;
    virtual ~Expression(){}
};

// 5 + (10 + 1)
class OperationExpression : public Expression {
    std::string operatorSymbol;
    Expression* leftHandSide;
    Expression* rightHandSide;
public:
    OperationExpression(const std::string& operatorSymbol, Expression* lhs, Expression* rhs) : operatorSymbol(operatorSymbol), leftHandSide(lhs), rightHandSide(rhs) {};
    ~OperationExpression() {
        delete leftHandSide;
        delete rightHandSide;
    }
    int evaluate() override {
        if (operatorSymbol == "+") {
            return leftHandSide->evaluate() + rightHandSide->evaluate();
        }
        else if (operatorSymbol == "-") {
            return leftHandSide->evaluate() - rightHandSide->evaluate();
        }
        else {
            std::cout << "Unrecognized operator: " << operatorSymbol;
            return 0;
        }
    }


};

class NumberExpression : public Expression {
    std::string numberString;
public:
    NumberExpression(const std::string& numberString) : numberString(numberString) {};
    int evaluate() override {
        return std::stoi(numberString);
    }
};

void InterpreterPattern::examples(){

    Expression* op = new OperationExpression("+", new NumberExpression("3"), new NumberExpression("5"));
    cout << "5 + 3 = " << op->evaluate() << endl;
    delete op;
}
void InterpreterPattern::execute() {
	std::map<int, int> limits = { {4, 39},{41, 44} };
	Context::execute(limits, "InterpreterPattern.cpp");
}