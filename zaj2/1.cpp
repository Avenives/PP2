#include <iostream>
using namespace std;

class Prostokat
{
    public:
        int a, b;
        int area()
        {
            return a*b;
        }
        int perimeter()
        {
            return 2*a+2*b;
        }
};

class Kolo
{

    public:
        int r;
        double area()
        {
            return 3.14*r*r;
        }
        double perimeter()
        {
            return 2*3.14*r;
        }
};

int main()
{
    Kolo kolo1;
    kolo1.r=1;
    cout << kolo1.area() << endl;
    cout << kolo1.perimeter() << endl;

    Prostokat p1;
    p1.a=2;
    p1.b=3;
    cout << p1.area() << endl;
    cout << p1.perimeter() << endl;

}
