#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={4,5,2,25};
    int n=arr.size();
    vector<int> ans=nextGreaterElement(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
vector<int> nextGreaterElement(vector<int>& arr, int n){
        vector<int> ans;
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                ans.push_back(-1);
            }else if(!s.empty() && s.top()>arr[i]){
                ans.push_back(s.top());
            }else if(!s.empty() && s.top()<=arr[i]){
                while(!s.empty() && s.top()<=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(-1);
                }else{
                    ans.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

