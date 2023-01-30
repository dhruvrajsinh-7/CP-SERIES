#include <bits/stdc++.h>
using namespace std;
vector<int> closestDivisors(int x)
{
    for (int a = sqrt(x + 2); a > 0; --a)
        for (auto i : {x + 1, x + 2})
            if (i % a == 0)
                return {a, i / a};
    return {};
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = closestDivisors(n);
    cout << ans[1] << " " << ans[0];
    return 0;
}