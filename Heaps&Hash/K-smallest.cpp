#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    for (int i = r; i >= 0; i--)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << kthSmallest(arr, 0, n - 1, k);
    return 0;
}