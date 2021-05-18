#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> all_subsets;

void subsets(vector<int> &curr_subset, int pos, vector<int> &arr)
{
    if (pos == arr.size())
    {
        all_subsets.push_back(curr_subset);
        return;
    }
    subsets(curr_subset, pos + 1, arr);
    curr_subset.push_back(arr[pos]);
    subsets(curr_subset, pos + 1, arr);
    curr_subset.pop_back();
}

int main()
{
    vector<int> empty;
    vector<int> arr = {1, 2, 3};
    subsets(empty, 0, arr);
    for (auto v : all_subsets)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}