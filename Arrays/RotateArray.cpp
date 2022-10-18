#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums{1,2,3,4,5,6,7};
    int k=3;
    rotate(nums,k);
    return 0;
}
void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>ans(n);
        int j=0;
        for(int i=n-k;i<n;i++){
            ans[j++]=nums[i];
        }
        for(int i=0;i<n-k;i++){
            ans[j++]=nums[i];
        }
       nums=ans;        
}
