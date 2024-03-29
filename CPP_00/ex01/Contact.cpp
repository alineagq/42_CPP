#include "Contact.hpp"
#include <iostream>

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {
  std::cout << "Contact created" << std::endl;
}

Contact::Contact(const std::string& first, const std::string& last, const std::string& nick,
                 const std::string& phone, const std::string& secret)
  : first_name(first), last_name(last), nickname(nick), phone_number(phone), darkest_secret(secret) {
    std::cout << "Contact " << first_name << " " << last_name << " created" << std::endl;
  }

std::string Contact::getFirstName() const {
  return first_name;
}

std::string Contact::getLastName() const {
  return last_name;
}

std::string Contact::getNickname() const {
  return nickname;
}

std::string Contact::getPhoneNumber() const {
  return phone_number;
}

std::string Contact::getDarkestSecret() const {
  return darkest_secret;
}

bool Contact::is_empty() const {
  return (first_name.empty() || last_name.empty() || nickname.empty() ||
          phone_number.empty() || darkest_secret.empty());
}

Contact::~Contact() {
    std::cout << "Contact " << first_name << " " << last_name << " destroyed" << std::endl;
}
