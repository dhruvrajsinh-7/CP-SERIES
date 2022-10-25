#include<bits/stdc++.h>
using namespace std;
int  main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int row_start=0,row_end=n-1,col_start=0,col_end=m-1;
     spiralOrder(arr);
}
     vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
    vector<int> ans;
    if (matrix.size() <= 0 || matrix[0].size() <= 0)
        return ans;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;
        
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
            ans.push_back(matrix[bottom][i]);
        bottom--;
        }

         if (left <= right) {
            for (int i = bottom; i >= top; i--)
              ans.push_back(matrix[i][left]);
        left++;
    }

    }
        return ans;

}
