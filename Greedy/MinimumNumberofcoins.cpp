#include <bits/stdc++.h>
using namespace std;
vector<int> minpartition(int N)
{
    // Your code goes here
    vector<int> deno = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> ans;

    for (int i = 0; i < deno.size(); i++)
    {

        while (N >= deno[i])
        {
            N -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = minpartition(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}