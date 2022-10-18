 #include<bits/stdc++.h>
 using namespace std;
 int main(){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
            cin>>nums[i];
        vector<int> ans=smallerNumbersThanCurrent(nums);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        return 0;
 }
 vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>copy (nums.begin(),nums.end());
        sort(copy.begin(),copy.end());
        unordered_map<int,int>map;
        for(int i=0;i<copy.size();i++){
            if(map.find(copy[i])==map.end()){
                map[copy[i]]=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=map[nums[i]];
        }
        return nums;
    }