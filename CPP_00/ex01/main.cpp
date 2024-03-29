#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
  PhoneBook phonebook;
  std::string command;

  while (true) {
    std::cout << "\n-- Crappy Awesome PhoneBook --" << std::endl;
    std::cout << "ADD, SEARCH or EXIT: ";
    std::getline(std::cin, command);

    if (command == "ADD") {
      phonebook.add_contact();
    } else if (command == "SEARCH") {
      phonebook.search_contact();
    } else if (command == "EXIT") {
      break;
    } else {
      std::cout << "Invalid command." << std::endl;
    }
  }

  std::cout << "Exiting program..." << std::endl;
  return 0;
}