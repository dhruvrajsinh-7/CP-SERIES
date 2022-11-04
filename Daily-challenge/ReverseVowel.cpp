 #include<bits/stdc++.h>
 using namespace std;
 int main(){
    string s;
    cin>>s;
    reverseVowels(s);
 }
 string reverseVowels(string s) {
        unordered_map<char,int> mp;
        string vowel = "aeiouAEIOU";
        for(auto ele : vowel){
            mp[ele]++;
        }
        int i=0,j=s.size()-1;
        while(i<j){
           if(mp.find(s[i])!=mp.end() && mp.find(s[j])!=mp.end()) {
                swap(s[i++],s[j--]);
            }
            else if (mp.find(s[i])==mp.end()) 
                i++;
            else if (mp.find(s[j])==mp.end()) 
                j--;
        }
        return s;
    }