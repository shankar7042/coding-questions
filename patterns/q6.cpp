#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif

    int row;
    cin >> row;
    int key = 1;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (key < 10)
            {
                cout << key << "  ";
            }
            else
            {
                cout << key << " ";
            }
            key++;
        }
        cout << endl;
    }
    return 0;
}