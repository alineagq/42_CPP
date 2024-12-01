#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
    RPN(const std::string &expression);
    RPN(const RPN &other);
    RPN& operator=(const RPN &other);
    ~RPN();

    void evaluate();

private:
    std::string expression;

    bool is_operator(const std::string &s);
    double apply_operator(double a, double b, const std::string &op);
    void print_result(double result);
};

#endif
