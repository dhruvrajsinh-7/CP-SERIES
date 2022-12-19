#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int source,destination;
    cin>>source>>destination;
    vector<vector<int>>edges(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    return validPath(n,edges,source,destination);
}
bool solve(vector<int>adj[], int sv, int dest, int n, vector<bool>&vis){
    
    if(sv==dest) 
        return true;
    
    vis[sv]=true;
    
    for(auto it:adj[sv]){
        if(!vis[it]){
            if(solve(adj,it,dest,n,vis)){
                return true;
            }
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    
    vector<bool>vis(n);
    
    vector<int>adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    return solve(adj,source,destination,n,vis);
    
}