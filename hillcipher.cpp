#include <bits/stdc++.h>
using namespace std;
int main()
{
    int key[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    string msg = "act";
    int msgsize = msg.length();
    int row = 3;
    int col = 3;
    int msgmat[3][1];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            msgmat[i][j] = msg[i] - 'a';
        }
    }
    int ciphermat[3][1];
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ciphermat[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                ciphermat[i][j] += key[i][k] * msgmat[k][j];
            }
            ciphermat[i][j] = ciphermat[i][j] % 26;
        }
    }
    cout << "Cipher text is:";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << (char)(ciphermat[i][j] + 'a');
        }
    }
    cout<<endl;
    cout<<"Prepared by :20DCE034";
    return 0;
}
