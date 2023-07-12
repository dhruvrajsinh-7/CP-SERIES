#include <bits/stdc++.h>
using namespace std;
vector<int> parents;
void unionize(int a, int b);
int find(int node);
long long countPairs(int n, vector<vector<int>> &edges)
{
    parents.resize(n);
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }

    for (vector<int> &edge : edges)
    {
        unionize(edge[0], edge[1]);
    }

    unordered_map<int, int> count;
    for (int i = 0; i < n; i++)
    {
        count[find(i)]++;
    }

    long long total = n;
    long long res = 0;
    for (auto &[key, val] : count)
    {
        total -= val;
        res += (val * total);
    }
    return res;
}

void unionize(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa != pb)
    {
        parents[pa] = pb;
    }
}

int find(int node)
{
    if (parents[node] == node)
        return node;
    return parents[node] = find(parents[node]);
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    cout << countPairs(n, edges);
    return 0;
}