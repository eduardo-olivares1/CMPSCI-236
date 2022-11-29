#include <iostream>

using namespace std;

void show(double *rates, int arrSize)
{
    for (int i = 0; i < arrSize; i++, rates++)
    {
        cout << *rates << endl;
    }
}

int main()
{
    const int ARRSIZE = 9;
    double rates[ARRSIZE] = {6.5, 7.2, 7.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0};

    show(rates, ARRSIZE);

    return 0;
}