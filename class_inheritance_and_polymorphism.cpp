#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle
{
protected:
    double length;
    double width;

public:
    Rectangle(double l = 0.00, double w = 0.00);
    double area();
};
Rectangle::Rectangle(double l, double w)
    : length{l}, width{w}
{
}
double Rectangle::area()
{
    return this->length * this->width;
}

class Box : public Rectangle
{
private:
    double depth;

public:
    Box(double l = 0.00, double w = 0.00, double d = 0.00);
    double area();
    double volume();
};
Box::Box(double l, double w, double d)
    : Rectangle{l, w}, depth{d}
{
}
double Box::area()
{
    return (2 * this->length * this->width) + (2 * this->length * this->depth) + (2 * this->depth * this->width);
}
double Box::volume()
{
    return this->length * this->width * this->depth;
}

int main()
{
    cout << fixed << setprecision(2);

    Rectangle myRectangle(5, 4);
    cout << "Area of myRectangle is: " << myRectangle.area() << endl;

    Box myBox(5, 10, 15);
    cout << "Area of myBox is: " << myBox.area() << endl;
    cout << "Volume of myBox is: " << myBox.volume() << endl;
    return 0;
}