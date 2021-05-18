#include <iostream>
using namespace std;

int main()
{
    int row;
    cin >> row;

    for (int i = 5; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}