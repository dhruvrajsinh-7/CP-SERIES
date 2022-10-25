    #include<bits/stdc++.h>
    using namespace std;
    int main(){

    }
    vector<int> majorityElement(vector<int>& arr) {
         unordered_map < int, int > mp;
         vector < int > ans;
         int n=arr.size();
         for (int i = 0; i < n; i++) {
             mp[arr[i]]++;
        }

        for (auto x: mp) {
            if (x.second > (n / 3))
                ans.push_back(x.first);
        }
        // if(ans.size()==0){
        //     ans.push_back(-1);
        // }
        sort(ans.begin(),ans.end());
        return ans;
    }