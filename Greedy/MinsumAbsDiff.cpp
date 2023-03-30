#include <bits/stdc++.h>
using namespace std;
long long findMinSum(vector<int> &A, vector<int> &B, int N)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += abs(A[i] - B[i]);
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    cout << findMinSum(A, B, n);
    return 0;
}