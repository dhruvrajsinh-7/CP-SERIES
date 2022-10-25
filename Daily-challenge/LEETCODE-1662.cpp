#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};
    return arrayStringsAreEqual(word1,word2);
}
bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    string dummy1;
    string dummy2;
    for (auto it : word1)
    {
        dummy1 += it;
    }
    for (auto ele : word2)
    {
        dummy2 += ele;
    }
    if (dummy1 == dummy2)
    {
        return true;
    }
    return false;
}