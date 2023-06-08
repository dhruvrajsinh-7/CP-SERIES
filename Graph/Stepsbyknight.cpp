#include <bits/stdc++.h>
using namespace std;
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    int X[] = {1, 2, 1, 2, -1, -2, -1, -2};
    int Y[] = {2, 1, -2, -1, 2, 1, -2, -1};

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    queue<pair<int, int>> q;
    q.push({KnightPos[0], KnightPos[1]});
    dp[KnightPos[0]][KnightPos[1]] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first, y = it.second;
        for (int i = 0; i < 8; i++)
        {
            int newx = x + X[i];
            int newy = y + Y[i];

            if (newx < 1 || newx > N || newy < 1 || newy > N || dp[newx][newy] != -1)
                continue;

            dp[newx][newy] = 1 + dp[x][y];
            q.push({newx, newy});
        }
    }

    return dp[TargetPos[0]][TargetPos[1]];
}
int main()
{
    vector<int> KnightPos = {4, 5};
    vector<int> TargetPos = {1, 1};
    int N = 6;
    cout << minStepToReachTarget(KnightPos, TargetPos, N);
}