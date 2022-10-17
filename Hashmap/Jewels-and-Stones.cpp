#include<bits/stdc++.h>
using namespace std;
int main(){
    string J,S;
    cin>>J>>S;
    numJewelsInStones(J,S);
    return 0;    
}
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        unordered_set<char> ans(jewels.begin(), jewels.end());
        for(int i=0;i<stones.size();i++){
            if(ans.count(stones[i]))
                count++;
        }
        return count;
    }