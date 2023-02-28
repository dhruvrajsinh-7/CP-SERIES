#include <bits/stdc++.h>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n)
{
    // code here
    long long count = 0;
    long long prefix_sum = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == 0)
            count += 1;
        if (mpp.find(prefix_sum) != mpp.end())
            ;
        count += mpp[prefix_sum];
        mpp[prefix_sum]++;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<long long int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findSubarray(arr, n);
    return 0;
}