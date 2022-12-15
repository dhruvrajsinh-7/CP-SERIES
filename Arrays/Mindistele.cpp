#include<bits/stdc++.h>
using namespace std;
int minDist(int arr[], int n, int x, int y) {
       int ans = 1e9,a = -1,b = -1;
       for(int i=0; i<n; i++)
       {
           if(arr[i] == x)
               a=i;
           if(arr[i] == y)
               b=i;
           if(a!=-1 && b!=-1)
               ans = min(ans,abs(a-b));
       }
       
       if(ans == 1e9 || ans == 0)
           return -1;
       else
           return ans;
    }
int main()
{
    int t;

    
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int x,y;
        cin>>x>>y;
        cout<<minDist(arr,n,x,y)<<endl;
    }
    return 0;
    
}
