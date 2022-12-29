#include <bits/stdc++.h>
using namespace std;
string encrypt(string s, int k)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += (char)((s[i] - 'a' + k) % 26 + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += (char)((s[i] - 'A' + k) % 26 + 'A');
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}
string decrypt(string s, int k)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += (char)((s[i] - 'a' - k + 26) % 26 + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += (char)((s[i] - 'A' - k + 26) % 26 + 'A');
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}
int main()
{
    string s;
    int k;
    cout << "Enter the message to be encrypted: ";
    getline(cin, s);
    cout << "Enter the key value: ";
    cin >> k;
    string encrypted = encrypt(s, k);
    cout << "Encrypted message: " << encrypted << endl;
    cout << "Decrypted message: " << decrypt(encrypted, k) << endl;
    cout << "Brute force attack on the encrypted message: " << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << "Key: " << i << " Decrypted message: " << decrypt(encrypted, i) << endl;
    }
    cout<<"prepared by 20DCE027"<<endl;
    return 0;

}