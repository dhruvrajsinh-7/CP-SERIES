#include <bits/stdc++.h>
using namespace std;
void helper(int index, vector<int> &ds, vector<vector<int>> &ans, int B, vector<int> &A)
{
    if (index == A.size())
    {
        if (B == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (A[index] <= B)
    {
        ds.push_back(A[index]);
        helper(index, ds, ans, B - A[index], A);
        ds.pop_back();
    }
    helper(index + 1, ds, ans, B, A);
}
vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<int> ds;
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    helper(0, ds, ans, B, A);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    combinationSum(A, n);
    return 0;
}