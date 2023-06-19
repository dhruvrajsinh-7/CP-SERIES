int longestIncreasingPath(vector<vector<int>> &matrix)
{
    if (matrix.empty())
    {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    int maxLength = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxLength = max(maxLength, dfs(matrix, i, j, memo));
        }
    }

    return maxLength;
}

int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo)
{
    if (memo[i][j] != 0)
    {
        return memo[i][j];
    }

    int m = matrix.size();
    int n = matrix[0].size();
    int maxLength = 1;

    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (auto dir : dirs)
    {
        int newRow = i + dir[0];
        int newCol = j + dir[1];

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && matrix[newRow][newCol] > matrix[i][j])
        {
            maxLength = max(maxLength, 1 + dfs(matrix, newRow, newCol, memo));
        }
    }

    memo[i][j] = maxLength;
    return maxLength;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << longestIncreasingPath(matrix);
    return 0;
}