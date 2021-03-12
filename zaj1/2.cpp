#include <iostream>
using namespace std;

int *doubleCopy(int *p, int *k)
{
    if(p==NULL || k==NULL) return NULL;

    int rozmiar = k-p;
    int *tab2 = new int[rozmiar];

    for(int i=0;i<rozmiar;++i)
    tab2[i] = (*(p+i))*2;

    return tab2;
}

int main()
{
    int tab[5]={2,5,20,50,1};
    int *k = tab+5;
    int *tab2=doubleCopy(tab,k);

    for(int i=0;i<5;++i)
        cout << tab[i] << " ";
    cout << endl;

    for(int i=0;i<5;++i)
        cout << *(tab2+i) << " ";


    delete[] tab2;
}
