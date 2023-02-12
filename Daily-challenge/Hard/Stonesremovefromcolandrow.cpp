#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;
void dfs(vector<vector<int>> &stones, vector<bool> &visited, int index)
{
    visited[index] = true;
    for (int i = 0; i < stones.size(); i++)
    {
        if (visited[i])
            continue;
        if (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])
        {
            dfs(stones, visited, i);
        }
    }
}
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        dfs(stones, visited, i);
        count++;
    }
    return n - count;
}
int main()
{
    vector<vector<int>> stones;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        stones.push_back(temp);
    }
    cout << removeStones(stones);
}