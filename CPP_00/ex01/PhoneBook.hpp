#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
  PhoneBook();
  
  void add_contact();
  void search_contact() const;

  ~PhoneBook();
private:
  Contact contacts[8];
  int num_contacts;

  void print_contact(int index) const;
  std::string get_input(const std::string& prompt) const;

};

#endif