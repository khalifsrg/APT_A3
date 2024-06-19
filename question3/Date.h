#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
public:
    // Constructors
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(const Date& other);
    Date(Date&& other) noexcept;
    Date(unsigned long dayNumber);

    // Destructor
    ~Date();

    // Getters
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    unsigned long getDayNumber() const;

    // Setters
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    void setDate(unsigned long dayNumber);

    // Operators
    Date& operator=(const Date& other);
    Date& operator=(Date&& other);
    Date& operator++(); // prefix ++
    Date operator++(int); // postfix ++
    Date& operator--(); // prefix --
    Date operator--(int); // postfix --
    unsigned int& operator[](const std::string& index);

    // Arithmetic operators
    Date& operator+=(int numDays);
    Date& operator-=(int numDays);
    Date operator+(int numDays) const;
    Date operator-(int numDays) const;

    // Comparison operators
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>=(const Date& other) const;

    // Friend function to assist in outputting date
    friend std::ostream& operator<<(std::ostream& os, const Date& date);

    // - operator that was missing due to, only operator that is an int
    int operator-(const Date& other) const;

private:
    // Unmodified
    unsigned int year;
    unsigned int month;
    unsigned int day;

    // Helper functions (Due to not having a Helper file)
    unsigned long calculateDayNumber() const;
    void setDateFromDayNumber(unsigned long dayNumber);
    bool isValidDate(unsigned int year, unsigned int month, unsigned int day) const;
    bool isLeapYear(unsigned int year) const;
    unsigned int daysInMonth(unsigned int year, unsigned int month) const;
};

#endif // DATE_H
