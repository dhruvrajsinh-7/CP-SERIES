#include <bits/stdc++.h>
using namespace std;
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr2[j], arr1[k]);
            j++;
            k--;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
int main()
{
    int n, m;
    cin >> n >> m;
    long long a1[n], a2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a2[i];
    }
    merge(a1, a2, n, m);
    for (int i = 0; i < n; i++)
    {
        cout << a1[i];
    }
    for (int j = 0; j < m; j++)
    {
        cout << a2[j];
    }
    return 0;
}
