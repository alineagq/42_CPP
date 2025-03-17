#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <stack>
#include <cctype>

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
    std::stack<int> stack;

    while (iss >> token) {
        if (is_operator(token)) {
            if (stack.size() < 2) {
                throw std::exception();
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = apply_operator(a, b, token);
            stack.push(result);
        } else {
            if (token.find_first_not_of("0123456789") != std::string::npos) {
                throw std::exception();
            }
            int num;
            std::istringstream iss(token);
            if (!(iss >> num) || num < 0 || num > 9) {
                throw std::exception();
            }
            stack.push(num);
        }
    }

    if (stack.size() != 1) {
        throw std::exception();
    }

    print_result(stack.top());
}

bool RPN::is_operator(const std::string &s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int RPN::apply_operator(int a, int b, const std::string &op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::exception();
        return a / b;
    }
    throw std::exception();
}

void RPN::print_result(int result) {
    std::cout << result << std::endl;
}