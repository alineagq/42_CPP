#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#define MAX_CONTACTS 8

PhoneBook::PhoneBook() : num_contacts(0) {}

void PhoneBook::add_contact()
{
    std::string first = get_input("First name");
    std::string last = get_input("Last name");
    std::string nick = get_input("Nickname");
    std::string phone = get_input("Phone number");
    std::string secret = get_input("Darkest secret");

    if (num_contacts == MAX_CONTACTS)
    {
        std::cout << "Phonebook is full. Replacing oldest contact." << std::endl;
        for (int i = 1; i < MAX_CONTACTS; ++i)
        {
            contacts[i - 1] = contacts[i];
        }
        num_contacts--;
    }
    contacts[num_contacts++] = Contact(first, last, nick, phone, secret);
}

std::string PhoneBook::get_input(const std::string& prompt) const
{
    std::string input;
    do
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, input);
    } while (input.empty());
    return input;
}

static void print_header()
{
    std::cout << std::right << std::setw(10) << "Index" << " | ";
    std::cout << std::right << std::setw(10) << "First name" << " | ";
    std::cout << std::right << std::setw(10) << "Last name" << " | ";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
}

void PhoneBook::search_contact() const
{
    if (num_contacts == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    print_header();
    for (int i = 0; i < num_contacts; ++i)
        print_contact(i);
    std::string index = get_input("Index");
    if (index == "EXIT")
        return;
    std::istringstream iss(index);
    int idx;
    iss >> idx;
    if (!iss.fail() && idx >= 0 && idx < num_contacts)
    {
        std::cout << "- First name : " << contacts[idx].getFirstName() << std::endl;
        std::cout << "- Last name : " << contacts[idx].getLastName() << std::endl;
        std::cout << "- Nickname : " << contacts[idx].getNickname() << std::endl;
        std::cout << "- Phone number : " << contacts[idx].getPhoneNumber() << std::endl;
        std::cout << "- Darkest secret : " << contacts[idx].getDarkestSecret() << std::endl;
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
    std::cout << std::right << std::setw(10) << (contacts[index].getFirstName().length() > 10 ? contacts[index].getFirstName().substr(0, 9) + "." : contacts[index].getFirstName()) << " | ";
    std::cout << std::right << std::setw(10) << (contacts[index].getLastName().length() > 10 ? contacts[index].getLastName().substr(0, 9) + "." : contacts[index].getLastName()) << " | ";
    std::cout << std::right << std::setw(10) << (contacts[index].getNickname().length() > 10 ? contacts[index].getNickname().substr(0, 9) + "." : contacts[index].getNickname()) << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Phonebook destroyed" << std::endl;
}