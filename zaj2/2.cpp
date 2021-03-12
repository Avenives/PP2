#include <iostream>
using namespace std;

class Prostokat
{

    private:
        int a, b;
    public:
        int area()
        {
            return a*b;
        }
        int perimeter()
        {
            return 2*a+2*b;
        }

        void set_a(int new_a)
        {
            a=new_a;
        }

        void set_b(int new_b)
        {
            b=new_b;
        }

        int get_a() const{
            return a;
        }

        int get_b() const{
            return b;
        }
};

class Kolo
{
    private:
        int r;
        const double pi=3.14;
    public:
        double area()
        {
            return pi*r*r;
        }

        void set_r(int new_r)
        {
            r=new_r;
        }

        double perimeter()
        {
            return 2*pi*r;
        }

        int get_r() const{
            return r;
        }
};

int main()
{
    Kolo kolo;
    kolo.set_r(1);
    cout << kolo.area() << endl;
    cout << kolo.perimeter() << endl;

    Prostokat p1;
    p1.set_a(2);
    p1.set_b(3);
    cout << p1.area() << endl;
    cout << p1.perimeter() << endl;
    cout << p1.get_a() << endl;
    cout << p1.get_b() << endl;


}
