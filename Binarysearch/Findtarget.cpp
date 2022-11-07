#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int target=5;

    int ans= binarysearch(arr,10,target);
    return ans;
}
int binarysearch(int arr[], int n, int k) {
        int start=0;
        int end=n-1;
        while(start<=end){
          int mid = (start+end)/2;
            if(arr[mid] == k){
                return mid;
                
            }else if(arr[mid] < k){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
            return -1;
    }





