#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1.getName() << std::endl;
        std::cout << b1.getGrade() << std::endl;
        Form f1("Form1", 1, 50);
        std::cout << f1.getName() << std::endl;
        std::cout << f1.isSigned() << std::endl;
        std::cout << f1.getGradeToSign() << std::endl;
        std::cout << f1.getGradeToExecute() << std::endl;
        std::cout << b1;
        std::cout << f1;
        b1.signForm(f1);
        std::cout << f1;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("Bob", 150);
        Form f2("Form2", 100, 50);
        std::cout << b2;
        std::cout << f2;
        b2.signForm(f2); // This should throw an exception
        std::cout << f2;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 75);
        Form f3("Form3", 75, 50);
        std::cout << b3;
        std::cout << f3;
        b3.signForm(f3);
        std::cout << f3;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
