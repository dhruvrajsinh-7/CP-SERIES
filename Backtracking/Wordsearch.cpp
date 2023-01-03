#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool existRe(vector<vector<char>> &board, string &word, int start, int x, int y, vector<vector<bool>> &visited)
{
    if (start == word.size())
        return true;
    int m = board.size(), n = board[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[start])
        return false;
    visited[x][y] = true;
    bool res = existRe(board, word, start + 1, x - 1, y, visited) ||
               existRe(board, word, start + 1, x + 1, y, visited) ||
               existRe(board, word, start + 1, x, y - 1, visited) ||
               existRe(board, word, start + 1, x, y + 1, visited);
    visited[x][y] = false;
    return res;
}
bool exist(vector<vector<char>> &board, string word)
{
    if (board.empty() || board[0].empty())
        return false;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (existRe(board, word, 0, i, j, visited))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<char>> board;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        vector<char> row;
        for (int j = 0; j < n; ++j)
        {
            char c;
            cin >> c;
            row.push_back(c);
        }
        board.push_back(row);
    }
    cout << "enter the word to be searched:";
    string word;
    cin >> word;
    if (exist(board, word))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}