#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

PhoneBook::PhoneBook() : num_contacts(0) {}

void PhoneBook::add_contact()
{
    std::string first = get_input("First name");
    std::string last = get_input("Last name");
    std::string nick = get_input("Nickname");
    std::string phone = get_input("Phone number");
    std::string secret = get_input("Darkest secret");

    if (num_contacts == 8)
    {
        std::cout << "Phonebook is full. Replacing oldest contact." << std::endl;
        for (int i = 1; i < 8; ++i)
        {
            contacts[i - 1] = contacts[i];
        }
        num_contacts--;
    }
    contacts[num_contacts++] = Contact(first, last, nick, phone, secret);
}

std::string PhoneBook::get_input(const std::string& prompt)
{
    std::string input;
    do
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, input);
    } while (input.empty());
    return input;
}

void PhoneBook::search_contact()
{
    std::string index;
    std::cout << "Enter contact index (0-" << num_contacts - 1 << "): ";
    std::getline(std::cin, index);
    std::istringstream iss(index);
    int idx;
    iss >> idx;
    if (!iss.fail() && idx >= 0 && idx < num_contacts)
    {
        print_contact(idx);
    }
    else
    {
        std::cout << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void PhoneBook::print_contact(int index) const
{
    std::cout << std::right << std::setw(10) << index << " | ";
    std::cout << std::right << std::setw(10) << contacts[index].getFirstName().substr(0, 10) << ". | ";
    std::cout << std::right << std::setw(10) << contacts[index].getLastName().substr(0, 10) << ". | ";
    std::cout << std::right << std::setw(10) << contacts[index].getNickname().substr(0,10) << std::endl;
    std::cout << "- Phone number : " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "- Darkest secret : " << contacts[index].getDarkestSecret() << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Phonebook destroyed" << std::endl;
}