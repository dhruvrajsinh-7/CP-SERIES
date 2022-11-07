 #include<bits/stdc++.h>
 using namespace std;
 int main(){
    int num;
    cin>>num;
    int ans=0;
    ans=maximum69Number(num);
    cout<<ans;
 }
 int maximum69Number (int num){
        string numString = to_string(num);
        for (auto &currChar : numString) {
            if (currChar == '6') {
                currChar = '9';
                break;
            }
        }
        return stoi(numString);
    }