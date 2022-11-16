#include <bits/stdc++.h>
using namespace std;
int guess(int num); 
//IT IS AN API IN LEETCODE WHICH RETURNS 1 IF THE NUMBER IS CORRECT, -1 IF THE NUMBER IS SMALLER THAN THE GUESS AND 1 IF THE NUMBER IS GREATER THAN THE GUESS
int binarysearch(int n, int s, int e)
{
    int mid;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int ans = guess(mid);
        if (ans > 0)
        {
            s = mid + 1;
        }
        else if (ans < 0)
        {
            e = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return mid;
}
int guessNumber(int n)
{
    int ans = binarysearch(n, 0, n - 1);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << guessNumber(n);
}