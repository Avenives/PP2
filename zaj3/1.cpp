#include <iostream>
#include <vector>
using namespace std;

class Zwierze
{
    protected:
        string gatunek;
        string imie;
    public:
        void set_gatunek(string new_gatunek)
        {
            gatunek=new_gatunek;
        }

        void set_imie(string new_imie)
        {
            imie=new_imie;
        }

        string get_gatunek() const{
            return gatunek;
        }

        string get_imie() const{
            return imie;
        }
};

class CzlowiekZnanyZInternetu
{
    protected:
        string gdziePoznany;
        string czymZwrocilMojaUwage;

    public:
        void set_gdziePoznany(string new_gdziePoznany)
        {
            gdziePoznany=new_gdziePoznany;
        }

        void set_czymZwrocilMojaUwage(string new_czymZwrocilMojaUwage)
        {
            czymZwrocilMojaUwage=new_czymZwrocilMojaUwage;
        }
};

class CzlowiekZnanyZWidzenia
{
    protected:
        string cechaCharakterystyczna;

    public:
        void set_cechaCharakterystyczna(string new_cechaCharakterystyczna)
        {
            cechaCharakterystyczna=new_cechaCharakterystyczna;
        }
};


class CzlowiekZnanyZImienia :public CzlowiekZnanyZWidzenia
{
    protected:
        string imie;

    public:
        void set_imie(string new_imie)
        {
            imie=new_imie;
        }
};

class DobrzeZnanyKolega :public CzlowiekZnanyZImienia, public CzlowiekZnanyZInternetu
{
    protected:
        string skadGoZnam;
        Zwierze zwierzeDomowe;

    public:
        void set_skadGoZnam(string new_skadGoZnam)
        {
            skadGoZnam=new_skadGoZnam;
        }

        void set_zwierzeDomowe(Zwierze new_zwierzeDomowe)
        {
            zwierzeDomowe.set_gatunek(new_zwierzeDomowe.get_gatunek());
            zwierzeDomowe.set_imie(new_zwierzeDomowe.get_imie());
        }
};

int main()
{
    Zwierze Kotek;
    Kotek.set_gatunek("Kot");
    Kotek.set_imie("Pies");

    DobrzeZnanyKolega Kolega;
    Kolega.set_skadGoZnam("z klasy");
    Kolega.set_zwierzeDomowe(Kotek);

    Kolega.set_imie("Zahariasz");
    Kolega.set_cechaCharakterystyczna("Pieprzy na nosie");
    Kolega.set_gdziePoznany("w internecie");
    Kolega.set_czymZwrocilMojaUwage("byl mily");
}
