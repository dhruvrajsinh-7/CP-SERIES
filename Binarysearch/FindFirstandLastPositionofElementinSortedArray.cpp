#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v = {5,7,7,8,8,10};
    int target = 8;
    searchRange(v,target);
}
vector<int> searchRange(vector<int>& v, int key) {
        vector<int>res;
        int ans=binarySearch(v,key);
        int ans1=binarySearch1(v,key);
        res.push_back(ans);
        res.push_back(ans1);
        return res;
    }
int binarySearch(vector<int>& nums, int target){
         int s=0,e=nums.size()-1;
         int index=-1; 
        while(s<= e) {
            int mid = s + (e - s) / 2;
            if(target<=nums[mid]){
                e= mid - 1;
            }else{
                s = mid + 1;
            }
            if(nums[mid] == target) 
                index = mid;
            }
    return index;
    }
int binarySearch1(vector<int>& nums, int target){
         int s=0,e=nums.size()-1;
         int index=-1;
        while(s<= e) {
            int mid = s + (e - s) / 2;
            if(target>=nums[mid]){
                 s =mid+1;
            }else{
                 e =mid-1;
            }
            if(nums[mid] == target) 
                index = mid;
    }
    return index;
  }