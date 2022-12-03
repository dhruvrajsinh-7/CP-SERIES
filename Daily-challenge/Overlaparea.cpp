#include <bits/stdc++.h>
using namespace std;
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int area1, area2, areacovered = 0;
    area1 = (ay2 - ay1) * (ax2 - ax1);
    area2 = (bx2 - bx1) * (by2 - by1);
    int r = min(ax2, bx2);
    int l = max(ax1, bx1);
    int xside = r - l;
    int t = min(by2, ay2);
    int b = max(by1, ay1);
    int yside = t - b;
    xside > 0 &&yside > 0 ? areacovered = xside * yside : 0;
    int totalarea = 0;
    totalarea = area1 + area2 - areacovered;
    return totalarea;
}
int main()
{
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;
    cout << computeArea(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2) << endl;
    return 0;
}