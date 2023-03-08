#include <bits/stdc++.h>
using namespace std;
long long timetaken(vector<int> &time, long long sec)
{
    long long cnt = 0;
    for (auto it : time)
    {
        cnt += sec / it;
    }
    return cnt;
}
long long minimumTime(vector<int> &time, int totalTrips)
{
    long long start = 0;
    long long end = 1e14, ans = 1e14;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (timetaken(time, mid) >= totalTrips)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> time = {1, 2, 3};
    int totalTrips = 1;
    cout << minimumTime(time, totalTrips);
    return 0;
}