#include <bits/stdc++.h>
using namespace std;
long long helper(int idx, vector<long long> &dp, vector<vector<int>> &questions)
{
    if (idx >= questions.size())
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    dp[idx] = max(helper(idx + 1, dp, questions), questions[idx][0] + helper(idx + 1 + questions[idx][1], dp, questions));
    return dp[idx];
}
long long mostPoints(vector<vector<int>> &questions)
{
    vector<long long> dp(questions.size(), -1);
    return helper(0, dp, questions);
}
int main()
{
    vector<vector<int>> questions = {{2, 2}, {2, 2}, {2, 2}, {2, 2}};
    cout << mostPoints(questions);
    return 0;
}