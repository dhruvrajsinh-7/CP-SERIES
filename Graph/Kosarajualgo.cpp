#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

void newdfs(int node, vector<int> &vis, vector<int> adjT[])
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            newdfs(it, vis, adjT);
        }
    }
}
// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    // code here
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    int count = 0;
    while (!st.empty())
    {
        int a = st.top();
        st.pop();
        if (!vis[a])
        {
            count++;
            newdfs(a, vis, adjT);
        }
    }
    return count;
}
int main()
{
    int V = 5;
    vector<vector<int>> adj[V];
    adj[0].push_back({1});
    adj[1].push_back({2});
    adj[2].push_back({0});
    adj[2].push_back({3});
    adj[3].push_back({4});
    cout << kosaraju(V, adj);
}