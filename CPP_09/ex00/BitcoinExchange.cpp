#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>


/*****************************************
    Date class implementation
*****************************************/

Date::Date() : year(0), month(0), day(0) {}

Date::Date(const std::string& dateStr) {
    if (!parse(dateStr)) {
        throw std::invalid_argument("Invalid date format: " + dateStr);
    }
}

Date::Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}

Date::~Date() {}

bool Date::parse(const std::string& dateStr) {
    if (std::sscanf(dateStr.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        return false;
    }
    return validate();
}

bool Date::validate() const {
    const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > days_in_month[month - 1]) return false;

    if (month == 2) {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (leap && day > 29) return false;
        if (!leap && day > 28) return false;
    }

    return true;
}

std::string Date::toString() const {
    char buffer[11];
    std::snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
    return std::string(buffer);
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}

/*****************************************
    BitcoinExchange class implementation
*****************************************/

BitcoinExchange::BitcoinExchange(const std::string &databaseFile) {
    loadDatabase(databaseFile);
}

void BitcoinExchange::loadDatabase(const std::string &databaseFile) {
    std::ifstream file(databaseFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::string dateStr, rateStr;
        double rate;

        size_t delimiter_pos = line.find(',');
        if (delimiter_pos == std::string::npos) {
            continue;
        }

        dateStr = line.substr(0, delimiter_pos);
        rateStr = line.substr(delimiter_pos + 1);

        std::istringstream rateStream(rateStr);
        if (!(rateStream >> rate) || rate < 0) {
            continue;
        }

        try {
            Date date(dateStr);
            if (!date.validate()) {
                continue;
            }

            exchangeRates[date] = rate;

        } catch (const std::invalid_argument&) {
            continue;
        }
    }
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
    Date queryDate(date);
    std::map<Date, double>::const_iterator it = exchangeRates.find(queryDate);

    if (it != exchangeRates.end()) {
        return it->second;
    }

    it = exchangeRates.lower_bound(queryDate);
    if (it != exchangeRates.begin()) {
        --it;
        return it->second;
    }

    return 0.0;
}
