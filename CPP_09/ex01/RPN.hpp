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
    int apply_operator(int a, int b, const std::string &op);
    void print_result(int result);
};

#endif