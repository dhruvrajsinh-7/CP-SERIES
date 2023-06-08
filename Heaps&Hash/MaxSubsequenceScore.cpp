#include <bits/stdc++.h>
using namespace std;

long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        pairs[i][0] = nums2[i];
        pairs[i][1] = nums1[i];
    }
    sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
         { return b[0] < a[0]; });
    priority_queue<int, vector<int>, greater<int>> pq;
    long res = 0, totalSum = 0;
    for (const vector<int> &pair : pairs)
    {
        pq.push(pair[1]);
        totalSum += pair[1];
        if (pq.size() > k)
        {
            totalSum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k)
        {
            res = max(res, totalSum * pair[0]);
        }
    }
    return res;
}
int main()
{
    vector<int> nums1 = {2, 4, 5, 8, 10};
    vector<int> nums2 = {4, 6, 8, 9};
    cout << maxScore(nums1, nums2, 3);
    return 0;
}
}