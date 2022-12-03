#include<stdio.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    cout<<halvesAreAlike(s);
    return 0;
}
int checkvowel(int i, string s, int j)
{
    int count = 0;
    for (int k = i; k <= j; k++)
    {
        if (s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u' || s[k] == 'A' || s[k] == 'E' || s[k] == 'I' || s[k] == 'O' || s[k] == 'U')
        {
            count++;
        }
    }
    return count;
}
bool halvesAreAlike(string s)
{
    int mid = (s.size() - 1) / 2;
    int l = checkvowel(0, s, mid);
    int r = checkvowel(mid + 1, s, s.size());
    if (l == r)
    {
        return true;
    }
    return false;
}