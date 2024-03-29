#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> &tree)
{
    unordered_map<int, int> count;
    int i, j;
    for (i = 0, j = 0; j < tree.size(); ++j)
    {
        count[tree[j]]++;
        if (count.size() > 2)
        {
            if (--count[tree[i]] == 0)
                count.erase(tree[i]);
            i++;
        }
    }
    return j - i;
}
int main()
{
    int n;
    cin >> n;
    vector<int> tree(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    cout << totalFruit(tree);
    return 0;
}