#include "Date.h"
#include <stdexcept>

/// @brief Constructors
Date::Date() : year(1970), month(1), day(1) {}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    if (!isValidDate(year, month, day)) {
        throw std::invalid_argument("Invalid date");
    }
    this->year = year;
    this->month = month;
    this->day = day;
}

Date::Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

Date::Date(Date&& other) noexcept : year(other.year), month(other.month), day(other.day) {}

Date::Date(unsigned long dayNumber) {
    setDate(dayNumber);
}

/// @brief Destructor
Date::~Date() {}

// Getters
unsigned int Date::getDay() const {
    return day;
}

unsigned int Date::getMonth() const {
    return month;
}

unsigned int Date::getYear() const {
    return year;
}

unsigned long Date::getDayNumber() const {
    return calculateDayNumber();
}

// Setters
void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    if (!isValidDate(year, month, day)) {
        throw std::invalid_argument("Invalid date!");
    }
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::setDate(unsigned long dayNumber) {
    setDateFromDayNumber(dayNumber);
}

// Operators
Date& Date::operator=(const Date& other) {
    if (this != &other) {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}

Date& Date::operator=(Date&& other) {
    if (this != &other) {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}

Date& Date::operator++() {
    *this += 1;
    return *this;
}

Date Date::operator++(int) {
    Date temp(*this);
    ++(*this);
    return temp;
}

Date& Date::operator--() {
    *this -= 1;
    return *this;
}

Date Date::operator--(int) {
    Date temp(*this);
    --(*this);
    return temp;
}

unsigned int& Date::operator[](const std::string& index) {
    if (index == "year") {
        return year;
    } else if (index == "month") {
        return month;
    } else if (index == "day") {
        return day;
    } else {
        throw std::out_of_range("Invalid index!");
    }
}

Date& Date::operator+=(int numDays) {
    unsigned long dayNum = calculateDayNumber();
    dayNum += numDays;
    setDateFromDayNumber(dayNum);
    return *this;
}

Date& Date::operator-=(int numDays) {
    unsigned long dayNum = calculateDayNumber();
    dayNum -= numDays;
    setDateFromDayNumber(dayNum);
    return *this;
}

Date Date::operator+(int numDays) const {
    Date result(*this);
    result += numDays;
    return result;
}

Date Date::operator-(int numDays) const {
    Date result(*this);
    result -= numDays;
    return result;
}

// Comparison operators
bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year < other.year)
        return true;
    if (year > other.year)
        return false;
    if (month < other.month)
        return true;
    if (month > other.month)
        return false;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}

bool Date::operator<=(const Date& other) const {
    return !(other < *this);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

/// @brief Subtract two dates to get the difference in days (Fix for error)
/// @param other 
/// @return the difference in days between the two given days
int Date::operator-(const Date& other) const {
    unsigned long thisDayNumber = getDayNumber();
    unsigned long otherDayNumber = other.getDayNumber();

    return (thisDayNumber >= otherDayNumber) ? static_cast<int>(thisDayNumber - otherDayNumber)
                                            : -static_cast<int>(otherDayNumber - thisDayNumber);
}

/// @brief friend operator to output the information
/// @param os 
/// @param date 
/// @return ostream
std::ostream& operator<<(std::ostream& os, const Date& date) {
    // Format date output in the desired format
    os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return os;
}

// Helper functions

/// @brief Calculates the number of days since "1st March 0000"
/// @return the number of days since "1st March 0000"
unsigned long Date::calculateDayNumber() const {
    unsigned long m = (month + 9) % 12;
    unsigned long y = year - m/10;
    return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (day - 1);
}

/// @brief set the date based on the calculation from calculateDayNumber() 
/// @param dayNumber Taken from the calculateDayNumber() function
void Date::setDateFromDayNumber(unsigned long dayNumber) {
    unsigned long y = (10000*dayNumber + 14780)/3652425;
    unsigned long ddd = dayNumber - (365*y + y/4 - y/100 + y/400);
    if (ddd < 0) {
        y = y - 1;
        ddd = dayNumber - (365*y + y/4 - y/100 + y/400);
    }
    unsigned long mi = (100*ddd + 52)/3060;
    unsigned long mm = (mi + 2)%12 + 1;
    y = y + (mi + 2)/12;
    unsigned long dd = ddd - (mi*306 + 5)/10 + 1;

    year = static_cast<unsigned int>(y);
    month = static_cast<unsigned int>(mm);
    day = static_cast<unsigned int>(dd);
}

/// @brief Returns true or false whether or not the date is valid
/// @param year The year to be checked
/// @param month The month to be checked
/// @param day The day to be checked
/// @return Returns true if the dat is valid, otherwise false
bool Date::isValidDate(unsigned int year, unsigned int month, unsigned int day) const {
    if (year < 1 || month < 1 || month > 12)
        return false;

    unsigned int daysInThisMonth = daysInMonth(year, month);
    return (day >= 1 && day <= daysInThisMonth);
}

/// @brief Checks if the given year is a leap year
/// @param year The year to be checked
/// @return Returns true if the year is a leap year, otherwise false
bool Date::isLeapYear(unsigned int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/// @brief Determines the number of days in a given month of a specified year
/// @param year The year in which the month occurs
/// @param month The month used to determine the number of days
/// @return The number of days of the given month in the specified year
unsigned int Date::daysInMonth(unsigned int year, unsigned int month) const {
    static const unsigned int days[] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};

    return (month == 2 && isLeapYear(year)) ? 29 : days[month - 1];
}
