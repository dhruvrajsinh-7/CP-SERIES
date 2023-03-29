#include <bits/stdc++.h>
using namespace std;
long long int minSum(int arr[], int n)
{
    sort(arr, arr + n);
    // Your code goes here
    long long num1 = 0;
    long long num2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            num1 = num1 * 10 + arr[i];
        }
        else
        {
            num2 = num2 * 10 + arr[i];
        }
    }
    return num1 + num2;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minSum(arr, n);
    return 0;
}