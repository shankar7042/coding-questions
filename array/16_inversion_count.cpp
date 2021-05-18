#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5 * 1e5;
ll bit[N] = {0};

// this method is used to create the fenwick tree
// method to add the value(x) at index i
void update(int i, int x)
{
	for (; i < N; i += (i & -i))
		bit[i] += x;
}

// this method return the sum of 1 to i i.e. if i = 10 then sum(10) is return sum of 1 -> 10
int sum(int i)
{
	int ans = 0;
	for (; i > 0; i -= (i & -i))
		ans += bit[i];
	return ans;
}

// ll int inversionCount(ll arr[], ll N)
// {
// 	ll count = 0;
// 	for (ll i = 0; i < N; i++)
// 		for (ll j = i + 1; j < N; j++)
// 			if (arr[i] > arr[j])
// 				count++;
// 	return count;
// }

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right)
{
	ll i = left,
	   j = mid + 1,
	   k = left,
	   inv_count = 0;

	while ((i <= mid) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

			inv_count += (mid - i + 1);
		}
	}

	while (i <= mid)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];

	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

ll mergeSort(ll arr[], ll temp[], ll left, ll right)
{
	ll mid, inv_count = 0;
	if (left < right)
	{
		mid = (left + right) / 2;

		inv_count += mergeSort(arr, temp, left, mid);
		inv_count += mergeSort(arr, temp, mid + 1, right);

		inv_count += merge(arr, temp, left, mid, right);
	}
	return inv_count;
}

// ll inversionCount(ll arr[], ll N)
// {
// 	ll temp[N];
// 	return mergeSort(arr, temp, 0, N - 1);
// }

ll inversionCount(ll arr[], ll size)
{
	ll inv_count = 0;
	for (int i = 1; i <= size; i++)
	{
		inv_count += sum(N) - sum(arr[i]);
		update(arr[i], 1);
	}
	return inv_count;
}

int main()
{
	ll size;
	cin >> size;
	ll arr[size + 10];
	for (ll i = 1; i <= size; i++)
		cin >> arr[i];
	for (ll i = 1; i <= size; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << inversionCount(arr, size);
	return 0;
}