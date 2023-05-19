#include <bits/stdc++.h>
using namespace std;
vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> v;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);
    for (int i = 0; i < k; i++)
    {
        v.push_back(pq.top());
        pq.pop();
    }

    return v;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> v = kLargest(arr, n, k);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}