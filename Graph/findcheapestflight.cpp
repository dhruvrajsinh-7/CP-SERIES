#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> flights(m,vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>flights[i][j];
        }
    }
    int src;
    cin>>src;
    int dst;
    cin>>dst;
    int k;
    cin>>k;
    cout<<findCheapestPrice(n,flights,src,dst,k);
    return 0;
}
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adjacency_list[n];
    for (auto it : flights)
    {
        adjacency_list[it[0]].push_back({it[1], it[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stop = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if (stop > k)
        {
            continue;
        }
        for (auto nd : adjacency_list[node])
        {
            int adjacency_node = nd.first;
            int weight = nd.second;
            if ((cost + weight) < distance[adjacency_node] && stop < k + 1)
            {
                distance[adjacency_node] = cost + weight;
                q.push({stop + 1, {adjacency_node, cost + weight}});
            }
        }
    }
    return (distance[dst] == 1e9) ? -1 : distance[dst];
}
