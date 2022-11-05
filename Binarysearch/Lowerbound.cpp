 #include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long> arr;
    long long target;
    cin>>target;
    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        arr.push_back(x);
    }
    int ans= findFloor(arr,n,target);
    return ans;
}
 int findFloor(vector<long long> v, long long N, long long x){
        // Your code here
        long long start=0; 
        long long end=N-1;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(v[mid] < x){
               start = mid + 1;
           }else if(v[mid] > x){
               end = mid - 1;
           }else{
               return mid;
           }
        }
        return end;
    }