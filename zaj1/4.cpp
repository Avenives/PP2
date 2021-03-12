#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> A)
{
    for(int i=0;i<A.size();++i)
    cout << A[i] << " ";
}

int main()
{
    vector<int> A;
    A.push_back(2);
    A.push_back(7);
    A.push_back(90);
    print(A);
}
