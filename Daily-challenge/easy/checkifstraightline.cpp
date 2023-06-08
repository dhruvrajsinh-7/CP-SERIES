#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int y = coordinates[0][1] - coordinates[1][1];
    int x = coordinates[0][0] - coordinates[1][0];

    for (int i = 0; i < coordinates.size() - 1; i++)
    {
        int y1 = coordinates[i + 1][1] - coordinates[i][1];
        int x1 = coordinates[i + 1][0] - coordinates[i][0];
        if (x1 * y != x * y1)
            return false;
    }

    return true;
}

int main()
{
    vector<vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    cout << checkStraightLine(coordinates);
}