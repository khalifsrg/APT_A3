#include "Date.h"
#include <exception>

Date::Date():
    year(1970), month(1), day(1)
{    
}

Date::Date(unsigned int year, unsigned int month, unsigned int day):
                        year(year), month(month), day(day)
{    
}

Date::Date(const Date& other){
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::Date(Date&& other){
    year = other.year;
    month = other.month;
    day = other.day;
}

Date::~Date(){
    
}

unsigned int Date::getDay(){
    return day;
}

unsigned int Date::getMonth(){
    return month;
}

unsigned int Date::getYear(){
    return year;
}


unsigned long Date::getDayNumber() const{
    unsigned long m = ((unsigned long)month + 9) % 12;
    unsigned long y = (unsigned long)year - ((unsigned long)month/10);
    return 365*y + y/4 - y/100 + y/400 
                + (m*306 + 5)/10 + ( (unsigned long)day - 1 );
}

void Date::setDate(unsigned long dayNumber){
    unsigned long y = (10000*((unsigned long)dayNumber) + 14780)/3652425;
    unsigned long ddd = (unsigned long)dayNumber - (365*y + y/4 - y/100 + y/400);
    if (ddd < 0){
        y = y - 1;
        ddd = (unsigned long)dayNumber - (365*y + y/4 - y/100 + y/400);
    }
    unsigned long mi = (100*ddd + 52)/3060;
    unsigned long mm = (mi + 2)%12 + 1;
    y = y + (mi + 2)/12;
    unsigned long dd = ddd - (mi*306 + 5)/10 + 1;

    this->day = (unsigned int)dd;
    this->month = (unsigned int)mm;
    this->year = (unsigned int)y;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day){
    this->day = day;
    this->month = month;
    this->year = year;
}


Date::Date(unsigned long dayNumber){
    this->setDate(dayNumber);
}

/*                                           */
/* YOU MAY ADD YOUR MODIFICATIONS HERE       */
/*                                           */