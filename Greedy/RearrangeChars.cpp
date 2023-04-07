#include <bits/stdc++.h>
using namespace std;
class Comp
{
public:
    bool operator()(pair<char, int> &p1, pair<char, int> &p2)
    {
        return p1.second < p2.second;
    }
};

string rearrangeString(string str)
{
    priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> pq;
    unordered_map<char, int> mp;
    for (char c : str)
        mp[c]++;

    for (auto m : mp)
    {
        pq.push({m.first, m.second});
    }

    string ans = "";
    while (!pq.empty())
    {
        auto tp = pq.top();
        pq.pop();
        if (ans.empty() || ans.back() != tp.first)
        {
            ans.push_back(tp.first);
            tp.second--;
            if (tp.second > 0)
                pq.push(tp);
        }
        else
        {
            if (pq.empty())
                return "-1";
            auto tp2 = pq.top();
            pq.pop();
            ans.push_back(tp2.first);
            tp2.second--;
            if (tp2.second > 0)
                pq.push(tp2);
            if (tp.second > 0)
                pq.push(tp);
        }
    }
    return ans;
}
int maim((){
    string str;
    cin >> str;
    cout << rearrangeString(str);
    return 0;
}