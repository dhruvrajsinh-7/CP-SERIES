#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<vector<int>> ans = threeSum(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> threeSum(vector<int> &num)
{
    vector<vector<int>> res;
    sort(num.begin(), num.end());

    for (int i = 0; i < num.size() - 2; i++)
    {

        if (i == 0 || (i > 0 && num[i] != num[i - 1]))
        {

            int lo = i + 1, hi = num.size() - 1, sum = 0 - num[i];

            while (lo < hi)
            {
                if (num[lo] + num[hi] == sum)
                {

                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[lo]);
                    temp.push_back(num[hi]);
                    res.push_back(temp);

                    while (lo < hi && num[lo] == num[lo + 1])
                        lo++;
                    while (lo < hi && num[hi] == num[hi - 1])
                        hi--;

                    lo++;
                    hi--;
                }
                else if (num[lo] + num[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return res;
}