#include <bits/stdc++.h>
using namespace std;

int m, n;
bool helper(vector<vector<char>> &board, string &word, int start, int x, int y, vector<vector<bool>> &vis)
{
    if (start == word.size())
        return true;
    m = board.size();
    n = board[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n ||
        vis[x][y] || board[x][y] != word[start])
        return false;
    vis[x][y] = true;
    bool res = helper(board, word, start + 1, x - 1, y, vis) ||
               helper(board, word, start + 1, x + 1, y, vis) ||
               helper(board, word, start + 1, x, y - 1, vis) ||
               helper(board, word, start + 1, x, y + 1, vis);
    vis[x][y] = false;
    return res;
}
bool exist(vector<vector<char>> &board, string word)
{
    if (board.empty() || board[0].empty())
        return false;
    m = board.size(), n = board[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (helper(board, word, 0, i, j, vis))
                return true;
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> board;
        for (int i = 0; i < m; i++)
        {
            vector<char> row;
            for (int j = 0; j < n; j++)
            {
                char x;
                cin >> x;
                row.push_back(x);
            }
            board.push_back(row);
        }
        string word;
        cin >> word;
        cout << exist(board, word) << endl;
    }
    return 0;
}