#include <bits/stdc++.h>
using namespace std;
int maxRepeating(int *arr, int n, int k)
{
    // code here
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int element = 0;
    int max = -10;
    for (auto it : mp)
    {
        if (it.second > max)
        {
            max = it.second;
            element = it.first;
        }
    }
    return element;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxRepeating(arr, n, k);
    return 0;
}