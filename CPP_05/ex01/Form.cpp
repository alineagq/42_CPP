#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        signedStatus = other.signedStatus;
    }
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const
{
    return name;
}

bool Form::isSigned() const
{
    return signedStatus;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    signedStatus = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << "Form " << f.getName() << ", signed: " << (f.isSigned() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute() << std::endl;
    return out;
}
