#include<bits/stdc++.h>
using namespace std;

int helper(string &s1, string &s2, int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(0 + dp[i - 1][j], 0 + dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int longestCommonSubsequence(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int ans = helper(s1, s2, m, n, dp);
    return ans;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<longestCommonSubsequence(s1,s2)<<endl;
    return 0;
}