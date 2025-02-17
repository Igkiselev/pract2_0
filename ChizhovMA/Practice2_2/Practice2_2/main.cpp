#include <iostream>
#include <fstream>
#include <string>
#include "person.h"
using namespace std;



int main()
{
    int n, a;
    Person* p;
    read(p, n);

    for (int i = 0; i < n; i++)
        cout<<p[i];
    Sort(p, n);

    do {
        cout << "\nHow do you want to display the sorted list?\n1. In alphabetical ascending order\n2. In alphabetical descending order\nEnter a number: ";
        cin >> a;
        if (a == 1)
        {
            cout << "\n";
            for (int i = 0; i < n; i++)
                cout << p[i];
        }
        if (a == 2)
        {
            cout << "\n";
            for (int i = n - 1; i >= 0; i--)
                cout << p[i];
        }
    } while ((a <= 0) || (a > 2));
    delete[]p;
    return 0;
}