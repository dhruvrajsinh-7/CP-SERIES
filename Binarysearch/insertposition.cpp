#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums;
    int target;
    cin>>target;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans= searchInsert(nums,target);
    return ans;
}
int searchInsert(vector<int>& nums, int target) {
       int s = 0 , e = nums.size() - 1 ,ans = -1;
        while(s<=e)
        {
        int mid =(s+e)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(target>nums[mid])
        {   s=mid+1;
            ans=mid+1;
        }
        else
        {    ans=mid;
            e=mid-1;
        }
        }
        return ans;
    }