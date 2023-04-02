#include <bits/stdc++.h>
using namespace std;
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{

    int n = potions.size();
    sort(potions.begin(), potions.end());
    vector<int> ans;
    for (auto it : spells)
    {
        int index = n;
        int left = 0;
        int right = potions.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long int temp = (long long int)it * (long long int)potions[mid];
            if (temp >= success)
            {
                right = mid - 1;
                index = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        ans.push_back(n - index);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> spells(n);
    for (int i = 0; i < n; i++)
    {
        cin >> spells[i];
    }
    vector<int> potions(n);
    for (int i = 0; i < n; i++)
    {
        cin >> potions[i];
    }
    long long success;
    cin >> success;
    vector<int> ans = successfulPairs(spells, potions, success);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}