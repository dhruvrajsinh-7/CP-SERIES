#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int s = 0, e = letters.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (letters[mid] <= target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    if (s == letters.size())
    {
        return letters[0];
    }
    else
    {
        return letters[s];
    }
}
int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    cout << nextGreatestLetter(letters, target);
    return 0;
}