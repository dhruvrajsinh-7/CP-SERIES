#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> rooms(n);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            rooms[i].push_back(x);
        }
    }
    canVisitAllRooms(rooms);

}
void helper(vector<vector<int>> &rooms, int s, vector<bool> &visited)
{
    visited[s] = true;
    for (int i = 0; i < rooms[s].size(); i++)
    {
        if (!visited[rooms[s][i]])
        {
            helper(rooms, rooms[s][i], visited);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    int i, n = rooms.size();
    vector<bool> visited(n, false);
    helper(rooms, 0, visited);
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}