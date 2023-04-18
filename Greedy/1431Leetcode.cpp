#include <bits/stdc++.h>
using namespace std;
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    vector<bool> res;
    int mx = *max_element(candies.begin(), candies.end());
    bool flag = true;
    for (auto it : candies)
    {
        if (it + extraCandies >= mx)
        {
            res.push_back(flag);
        }
        else
        {
            res.push_back(!flag);
        }
    }
    return res;
}
int main()
{
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> res = kidsWithCandies(candies, extraCandies);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}