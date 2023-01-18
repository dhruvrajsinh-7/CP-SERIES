#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int ans;
int longestPath(vector<int> &parent, string &s)
{
    int n = parent.size();
    if (n == 1)
        return 1;
    graph.resize(n);
    for (int i = 1; i < n; i++)
    {
        graph[parent[i]].push_back(i);
    }
    ans = 0;
    solve(s, 0);
    return ans;
}
int solve(string &s, int currPos)
{
    if (graph[currPos].size() == 0)
        return 1;
    int max1 = 0, max2 = 0;
    for (int i : graph[currPos])
    {
        int pathSum = solve(s, i);
        if (s[currPos] != s[i])
        {
            if (pathSum > max1)
            {
                max2 = max1;
                max1 = pathSum;
            }
            else if (pathSum > max2)
            {
                max2 = pathSum;
            }
        }
    }
    ans = max(ans, max1 + max2 + 1);
    return 1 + max1;
}
int main()
{
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    string s = "abaedcd";
    cout << longestPath(parent, s);
    return 0;
}