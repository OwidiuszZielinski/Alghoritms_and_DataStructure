#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Podaj liczbe elementow tablicy: ";
    cin >> n;
    float *T = NULL;
    T = new float[n]; // float *T=new float [n]
    for (int i = 0; i < n; i++)
    {
        cout << "T[" << i << "]=";
        cin >> T[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << T[i] << "\t";
    }
    cout << &T <<endl;
    cout << sizeof(T);
    delete[] T;
    return 0;
}