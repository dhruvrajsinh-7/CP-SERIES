 #include<bits/stdc++.h>
 using namespace std;
 int main(){

    cout<<removeDuplicates("abbaca")<<endl;
 }
 string removeDuplicates(string s) {
        string ans = "";
        for (char& c : s)
            if (ans.size()!=0 && c == ans.back())
                ans.pop_back();
            else
                ans.push_back(c);
        return ans;
    }