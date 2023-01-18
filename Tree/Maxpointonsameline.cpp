#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &points)
{
    int maxp = 1;
    for (int i = 0; i < points.size() - 1; i++)
    {
        map<double, int> mp;
        int duplicate = 0;
        for (int j = i + 1; j < points.size(); j++)
        {
            int y2 = points[j][1];
            int y1 = points[j][0];
            int x2 = points[i][1];
            int x1 = points[i][0];
            double dy = y2 - x2;
            double dx = y1 - x1;
            double slope;
            if (x1 == y1)
            {
                mp[1000001]++;
            }
            else
            {
                slope = (double)dy / dx;
                mp[slope]++;
            }
        }
        int temp = 0;
        for (auto it : mp)
        {
            temp = max(temp, it.second);
        }
        maxp = max(maxp, temp + 1);
    }
    return maxp;
}
int main(){
    vector<vector<int>>points={{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout<<maxPoints(points);
    return 0;
}