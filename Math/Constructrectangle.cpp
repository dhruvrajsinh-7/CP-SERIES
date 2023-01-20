#include<bits/stdc++.h>
using namespace std;
vector<int> constructRectangle(int area)
{
    vector<int> res;
    int width = 1;
    for (int i = 1; i <= sqrt(area); i++)
    {
        if (area % i == 0)
            width = i;
    }
    res.push_back(area / width);
    res.push_back(width);
    return res;
}
int main(){
    int area = 4;
    vector<int> ans = constructRectangle(area);
    for(auto i: ans)
        cout<<i<<" ";
    return 0;
}