#include <bits/stdc++.h>
using namespace std;
int maxConsecutiveAnswers(string answerKey, int k)
{
    unordered_map<char, int> count;
    for (int i = 0; i < k; i++)
    {
        count[answerKey[i]]++;
    }
    int left = 0;
    long long len = k;
    long long mini;
    for (int j = k; j < answerKey.size(); j++)
    {
        count[answerKey[j]]++;
        mini = min(count['T'], count['F']);
        while (mini > k)
        {
            count[answerKey[left]]--;
            left++;
            mini = min(count['T'], count['F']);
        }
        len = max(len, (long long)(j - left + 1));
    }
    return len;
}
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << maxConsecutiveAnswers(s, k);
    return 0;
}