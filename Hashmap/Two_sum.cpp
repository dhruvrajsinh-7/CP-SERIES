#include<bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>&nums,int target){
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        if(mp.find(target-nums[i])!=mp.end()){
            return {mp[target-nums[i]],i};
        }
        mp[nums[i]]=i;
    }
    return {};
}
int main(){
    vector<int>nums={2,7,11,15};
    int target=9;
    vector<int>ans=twosum(nums,target);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}