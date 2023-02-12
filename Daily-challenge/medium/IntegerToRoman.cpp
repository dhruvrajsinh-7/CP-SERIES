#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num)
{
    map<int, string> m;
    m[1] = "I";
    m[4] = "IV";
    m[5] = "V";
    m[9] = "IX";
    m[10] = "X";
    m[40] = "XL";
    m[50] = "L";
    m[90] = "XC";
    m[100] = "C";
    m[400] = "CD";
    m[500] = "D";
    m[900] = "CM";
    m[1000] = "M";
    string ans = "";
    while (num > 0)
    {
        if (m.find(num) != m.end())
        {
            ans += m[num];
            num = 0;
        }
        else
        {
            int temp = num;
            while (m.find(temp) == m.end())
            {
                temp--;
            }
            ans += m[temp];
            num -= temp;
        }
    }
    return ans;
}
