#include <bits/stdc++.h>
using namespace std;
int dfs(int arr[], int idx, int N, int k, vector<int> &dp)
{
    int take = 0, notTake = 0;
    if (dp[idx] != -1)
        return dp[idx];
    if (idx + 1 < N && arr[idx + 1] - arr[idx] < k)
    {
        take = arr[idx] + arr[idx + 1] + dfs(arr, idx + 2, N, k, dp);
    }
    if (idx + 1 < N)
        notTake = dfs(arr, idx + 1, N, k, dp);
    return dp[idx] = max(take, notTake);
}

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // Your code goes here
    sort(arr, arr + N);
    vector<int> dp(N + 1, -1);
    return dfs(arr, 0, N, K, dp);
}
int main()
{
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K);
    return 0;
}