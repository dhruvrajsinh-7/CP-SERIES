#include <bits/stdc++.h>
using namespace std;
int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int, vector<int>> pq(piles.begin(), piles.end());
    int sum = 0;
    while (pq.size() && k--)
    {
        int element = pq.top();
        pq.pop();
        element = element - element / 2;
        if (element)
        {
            pq.push(element);
        }
    }
    while (!pq.empty())
    {
        sum = sum + pq.top();
        pq.pop();
    }
    return sum;
}
int main()
{
    vector<int> piles;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        piles.push_back(x);
    }
    cout << minStoneSum(piles, k);
}