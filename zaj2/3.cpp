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

        Prostokat(int new_a)
        {
            a=new_a;
            b=new_a;
            cout << "Utworzono kwadrat o boku: " << a << endl;
        };

        Prostokat(int new_a, int new_b)
        {
            a=new_a;
            b=new_b;
            cout << "Utworzono Prostokat o bokach: " << a << " i " << b << endl;
        };
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

        Kolo(int new_r = 1 )
        {
            r=new_r;
            cout << "Utworzono kolo o promieniu: " << r << endl;
        }
};

int main()
{
    Prostokat p1(3);
    Prostokat p2(5, 2);
    Kolo k1();
    Kolo k2(23);
}
