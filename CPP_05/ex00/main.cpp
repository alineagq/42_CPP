#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1;
        b1.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("Bob", 150);
        std::cout << b2;
        b2.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 75);
        std::cout << b3;
        b3.incrementGrade();
        std::cout << b3;
        b3.decrementGrade();
        std::cout << b3;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
