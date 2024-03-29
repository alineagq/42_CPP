#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();
  Contact(const std::string& first, const std::string& last, const std::string& nick,
          const std::string& phone, const std::string& secret);
  
  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;

  bool is_empty() const;

  ~Contact();

private:
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;
};

#endif