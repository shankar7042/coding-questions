#include <bits/stdc++.h>
using namespace std;

// O(n1 + n2 + n3) and S(1)
// vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
// {
//     int i = 0,
//         j = 0,
//         k = 0;
//     vector<int> result;
//     while ((i < n1) && (j < n2) && (k < n3))
//     {
//         if ((A[i] == B[j]) && (A[i] == C[k]))
//         {
//             if (result.size() == 0)
//                 result.push_back(A[i]);
//             else if (result.back() != A[i])
//                 result.push_back(A[i]);

//             i++;
//             j++;
//             k++;
//         }
//         else if (A[i] < B[j])
//             i++;
//         else if (B[j] < C[k])
//             j++;
//         else k++;
//     }
//     return result;
// }

// O(n1 + n2 + n3) and S(n1 + n2 + n3)
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    unordered_map<int, int> m1, m2, m3;

    for (int i = 0; i < n1; i++) m1[A[i]]++;
    for (int i = 0; i < n2; i++) m2[B[i]]++;
    for (int i = 0; i < n3; i++) m3[C[i]]++;

    vector<int> result;
    for (int i = 0; i < n1; i++)
    {
        if (m1[A[i]] && m2[A[i]] && m3[A[i]])
        {
            result.push_back(A[i]);
            m1[A[i]] = 0; // to remove the element for which this can't be used again
        }
    }
    return result;
}

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];

        vector <int> res = commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0)
            cout << -1;
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}