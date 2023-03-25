#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> v;
    stack<int> s;
    unordered_map<int, int> m;
    int n = nums1.size();
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            v.push_back(m[nums2[i]] = -1);
        else if (s.size() > 0 && s.top() > nums2[i])
            v.push_back(m[nums2[i]] = s.top());
        else if (s.size() > 0 && s.top() <= nums2[i])
        {
            while (s.size() > 0 && s.top() <= nums2[i])
                s.pop();
            if (s.size() == 0)
                v.push_back(m[nums2[i]] = -1);
            else
                v.push_back(m[nums2[i]] = s.top());
        }
        s.push(nums2[i]);
    }
    reverse(v.begin(), v.end());
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(m[nums1[i]]);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}