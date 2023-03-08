#include <bits/stdc++.h>
using namespace std;
double timetaken(vector<int> &piles, int hour)
{
    double cnt = 0;
    for (auto it : piles)
    {
        cnt += ceil(double(it) / double(hour));
    }
    return cnt;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 1;
    int end = *max_element(piles.begin(), piles.end());
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (timetaken(piles, mid) <= h)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h);
    return 0;
}