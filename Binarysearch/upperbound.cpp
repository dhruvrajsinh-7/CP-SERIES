#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        auto ans=getFloorAndCeil(arr,n,x);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr, arr+n);
    int lo = 0, hi = n-1 ;
    int index = -1 ;
    int cl = -1 ;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2 ;
        if(arr[mid]==x){
            index = arr[mid];
            cl = arr[mid];
            break ;
        }
        else if(arr[mid] < x){
            index = arr[mid];
            lo = mid+1 ;
        }else{
            cl = arr[mid];
            hi = mid-1 ;
        }
    }
    return {index, cl};
}