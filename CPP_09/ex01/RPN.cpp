#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <stack>

RPN::RPN(const std::string &expression) : expression(expression) {}

RPN::RPN(const RPN &other) : expression(other.expression) {}

RPN& RPN::operator=(const RPN &other) {
    if (this != &other) {
        expression = other.expression;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::evaluate() {
    std::istringstream iss(expression);
    std::string token;
    std::stack<double> stack;

    while (iss >> token) {
        if (is_operator(token)) {
            if (stack.size() < 2) {
                throw std::invalid_argument("Error: insufficient values in expression");
            }
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            double result = apply_operator(a, b, token);
            stack.push(result);
        } else {
            double value;
            std::istringstream(token) >> value;
            if (iss.fail()) {
                throw std::invalid_argument("Error: invalid token => " + token);
            }
            stack.push(value);
        }
    }

    if (stack.size() != 1) {
        throw std::invalid_argument("Error: too many values in expression");
    }

    print_result(stack.top());
}

bool RPN::is_operator(const std::string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

double RPN::apply_operator(double a, double b, const std::string &op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::invalid_argument("Error: division by zero");
        return a / b;
    }
    throw std::invalid_argument("Error: unknown operator");
}

void RPN::print_result(double result) {
    std::cout << std::fixed << std::setprecision(0);
    std::cout << result << std::endl;
}
