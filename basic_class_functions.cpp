#include <iostream>
#include <iomanip>
using namespace std;
// declaration section
class Complex
{
private:
    double realPart;      // declare realPart as a double variable
    double imaginaryPart; // declare imaginaryPart as a double variable
public:
    Complex(double real = 0.0, double imag = 0.0) // inline constructor
    {
        realPart = real;
        imaginaryPart = imag;
    }
    void showComplexValues();                       // accessor prototype
    void assignNewValues(double real, double imag); // inline mutator
    void swap(Complex &b);
    Complex operator*(const Complex &);
    Complex operator+(const Complex &); // prototype for the addition operator
};                                      // end of class declaration
// implementation section
void Complex::showComplexValues() // accessor
{
    char sign = '+';
    if (imaginaryPart < 0)
        sign = '-';
    cout << realPart << ' ' << sign << ' ' << abs(imaginaryPart) << 'i';
}

Complex Complex::operator+(const Complex &complex2) //(a + bi) + (c + di) = (a + c) + (b + d)i
{
    Complex temp;
    temp.realPart = realPart + complex2.realPart;
    temp.imaginaryPart = imaginaryPart + complex2.imaginaryPart;
    return temp;
}

Complex Complex::operator*(const Complex &complex2)
{
    Complex temp;
    temp.realPart = (realPart * complex2.realPart) - (imaginaryPart * complex2.imaginaryPart);
    temp.imaginaryPart = (imaginaryPart * complex2.realPart) + (realPart * complex2.imaginaryPart);
    return (temp);
}

void Complex::swap(Complex& b)
{
    Complex temp;
    temp.realPart = b.realPart;
    temp.imaginaryPart = b.imaginaryPart;
    b.realPart = realPart;
    b.imaginaryPart = imaginaryPart;
    realPart = temp.realPart;
    imaginaryPart = temp.imaginaryPart;
}

int main()
{
    Complex a(2.3, 10.5), b(6.3, 19.2), c; // declare three objects
    cout << "Complex number a is ";
    a.showComplexValues();
    cout << "\nComplex number b is ";
    b.showComplexValues();
    c = a * b; // multiply two complex numbers
    cout << "\n\nThe product of a and b: ";
    c.showComplexValues();
    a.swap(b);
    cout << "\n\nComplex number a is ";
    a.showComplexValues();
    cout << "\nComplex number b is ";
    b.showComplexValues();
    return 0;
}
