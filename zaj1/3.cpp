#include <iostream>
using namespace std;


int main()
{
    string A="sfsdsdppGIIusdfdspd";

    for(auto &znak : A)
        if(znak=='d') znak='D';

    cout << A;
}
