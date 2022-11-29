#include <iostream>
#include <iomanip> // needed for formatting
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
    bool isWeekday();
    bool operator==(const Date &);
    bool operator>(const Date &);
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
bool Date::isWeekday()
{
    int weekDay = this->dayOfWeek();
    return weekDay >= 2 && weekDay <= 6;
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

int main()
{
    // Weekday
    Date dt1 = Date(11, 1, 2022);
    // Weekend
    Date dt2 = Date(10, 30, 2022);
    // True
    cout << (dt1 > dt2) << endl;
    // False
    cout << (dt2 > dt1) << endl;
    // False
    cout << (dt2.isWeekday()) << endl;
    // True
    cout << (dt1.isWeekday()) << endl;
    return 0;
}