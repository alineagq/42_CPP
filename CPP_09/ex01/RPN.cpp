#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>

double RPN::evaluate(const std::string& expression) {
    std::stack<double> operands;

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            operands.push(std::stod(token));
        } else if (isOperator(token[0])) {
            if (operands.size() < 2) {
                throw std::runtime_error("Not enough operands for operator " + token);
            }
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            double result;
            switch (token[0]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        throw std::runtime_error("Division by zero");
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    throw std::runtime_error("Invalid operator: " + token);
            }

            operands.push(result);
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    if (operands.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }

    return operands.top();
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
