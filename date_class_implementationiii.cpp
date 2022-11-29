#include <iostream>
#include <iomanip> // needed for formatting
#include <string>
using namespace std;
// declaration section
class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date(int mm = 1, int dd = 1, int yyyy = 2014) // inline constructor
    {
        month = mm;
        day = dd;
        year = yyyy;
    }
    void setDate(int mm, int dd, int yy) // inline mutator
    {
        month = mm;
        day = dd;
        year = yy;
    }
    void showDate(); // accessor
    bool isLeapYear();
    long convert() const;
    int dayOfWeek();
    string nameOfDay();
    bool isWeekday();
    void nextDay();
    void priorDay();
    bool operator==(const Date &);
    bool operator>(const Date &);
    Date operator+(int days);
};

// implementation section
void Date::showDate()
{
    cout << "The date is " << setfill('0')
         << setw(2) << month << '/'
         << setw(2) << day << '/'
         << setw(2) << year % 100; // extract the last two year digits
    cout << endl;
}
bool Date::isLeapYear()
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true; // is a leap year
    else
        return false; // is not a leap year
}
long Date::convert() const
{
    return year * 10000 + month * 100 + day; // YYYYMMDD
}
int Date::dayOfWeek()
{
    /*
    If the month is less than 3
    month = month + 12
    year = year - 1
    EndIf
    Set century = int(year/100)
    Set year = year % 100
    Set variable T = day + int(26 × (month + 1) / 10) + year + int(year / 4)
    + int(century / 4) - 2 × century
    Set dd = T % 7
    If dd is less than 0
    Set dd = dd + 7
    EndIf
    */

    int m = month;
    int y = year;

    if (month < 3)
    {
        m = m + 12;
        y = y - 1;
    }

    int c = int(y / 100);
    y = y % 100;

    int T = day + int(26 * (m + 1) / 10) + y + int(y / 4) + int(c / 4) - 2 * c;
    int dd = T % 7;
    if (dd < 0)
        dd += 7;

    return dd;
}
string Date::nameOfDay()
{

    int weekNumber = this->dayOfWeek();
    string day = "";

    switch (weekNumber)
    {
    case 1:
        day = "Sunday";
        break;

    case 2:
        day = "Monday";
        break;

    case 3:
        day = "Tuesday";
        break;

    case 4:
        day = "Wednesday";
        break;

    case 5:
        day = "Thursday";
        break;

    case 6:
        day = "Friday";
        break;

    case 7:
        day = "Saturday";
        break;

    default:
        day = "Invalid";
        break;
    }
    return day;
}
bool Date::isWeekday()
{
    int weekDay = this->dayOfWeek();
    return weekDay >= 2 && weekDay <= 6;
}
void Date::nextDay()
{
    int newMonth, newDay, newYear;
    newMonth = this->month;
    newDay = this->day;
    newYear = this->year;

    newDay += 1;
    while (newDay > 30)
    {
        newDay -= 30;
        ++newMonth;
        if (newMonth > 12)
        {
            newMonth = 1;
            ++newYear;
        }
    }

    this->month = newMonth;
    this->day = newDay;
    this->year = newYear;
}
void Date::priorDay()
{
    int newMonth, newDay, newYear;
    newMonth = this->month;
    newDay = this->day;
    newYear = this->year;

    newDay -= 1;
    if (newDay == 0)
    {
        newDay = 30;
        --newMonth;
        if (newMonth == 0)
        {
            newMonth = 12;
            --newYear;
        }
    }

    this->month = newMonth;
    this->day = newDay;
    this->year = newYear;
}
bool Date::operator==(const Date &date2)
{
    if (day == date2.day && month == date2.month && year == date2.year)
        return true;
    else
        return false;
}
bool Date::operator>(const Date &date2)
{
    long date1conv = this->convert();
    long date2conv = date2.convert();

    return date1conv > date2conv;
}
Date Date::operator+(int days)
{
    int newMonth, newDay, newYear;
    newMonth = this->month;
    newDay = this->day;
    newYear = this->year;

    newDay += days;
    while (newDay > 30)
    {
        newDay -= 30;
        ++newMonth;
        if (newMonth > 12)
        {
            newMonth = 1;
            ++newYear;
        }
    }

    return Date(newMonth, newDay, newYear);
}

int main()
{
    cout << "Addition Examples" << endl;
    cout << "-----------------" << endl;

    // Year+ example
    Date dt1 = Date(12, 30, 2011);
    dt1.showDate();
    dt1.nextDay();
    dt1.showDate();
    // Month+ Example
    Date dt2 = Date(3, 30, 2011);
    dt2.showDate();
    dt2.nextDay();
    dt2.showDate();
    // Normal day+ example
    Date dt3 = Date(3, 15, 2011);
    dt3.showDate();
    dt3.nextDay();
    dt3.showDate();

    cout << "\nSubtraction Examples" << endl;
    cout << "--------------------" << endl;
    // Year- example
    Date dt4 = Date(1, 1, 2011);
    dt1.showDate();
    dt1.priorDay();
    dt1.showDate();
    // Month- Example
    Date dt5 = Date(3, 1, 2011);
    dt2.showDate();
    dt2.priorDay();
    dt2.showDate();
    // Normal day- example
    Date dt6 = Date(3, 15, 2011);
    dt3.showDate();
    dt3.priorDay();
    dt3.showDate();

    return 0;
}