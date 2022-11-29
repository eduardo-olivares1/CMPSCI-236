#include <iostream>

using namespace std;

int convertdays(int month, int day, int year)
{
    int date = (year * 1000) + (month * 100) + day;
    return date;
}

int main()
{
    cout << convertdays(12, 6, 1988) << endl;
    cout << convertdays(2, 28, 2014) << endl;
    return 0;
}