#include <iostream>
#include "whatever.hpp"

int main() {
    int a = 2;
    int b = 3;
    
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    double e = 3.14;
    double f = 4.20;

    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

    bool t = true;
    bool x = false;

    ::swap(t, x);
    std::cout << "t = " << t << ", x = " << x << std::endl;
    std::cout << "min(t, x) = " << ::min(t, x) << std::endl;
    std::cout << "max(t, x) = " << ::max(t, x) << std::endl;

    return 0;
}