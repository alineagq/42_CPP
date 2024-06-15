#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    double evaluate(const std::string& expression);

private:
    bool isOperator(char c);
};

#endif // RPN_HPP
