#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &A, vector<int> &B)
{
    int i;
    int n = A.size();
    int m = B.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (i = 0; i < n; i++)
        pq.push(A[i]);

    for (i = 0; i < m; i++)
        pq.push(B[i]);

    int check = n + m;
    double count = -1;
    double mid1, mid2;
    while (!pq.empty())
    {
        count++;
        if (check % 2 != 0 && count == check / 2)
        {
            double ans = pq.top();
            return ans;
        }
        if (check % 2 == 0 && count == (check / 2) - 1)
            mid1 = pq.top();
        if (check % 2 == 0 && count == check / 2)
        {
            mid2 = pq.top();
            double ans = (mid1 + mid2) / 2;
            return ans;
        }
        pq.pop();
    }
    return 0.00000;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    cout << MedianOfArrays(A, B);
    return 0;
}