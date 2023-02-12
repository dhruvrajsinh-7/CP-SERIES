#include<bits/stdc++.h>
using namespace std; 
string orderlyQueue(string s, int k) {
        if(k==1){
            string res=s;
            string pos;
            for(int i=0;i<s.size();i++){
                pos=s.substr(i)+s.substr(0,i);
                res=min(res,pos);
            }
            return res;
        }
        sort(s.begin(),s.end());
        return s;
    }
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    string ans;
    ans=orderlyQueue(s,k);
    std::cout << ans << std::endl;
}


