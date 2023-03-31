#include <bits/stdc++.h>
using namespace std;
bool cmp(Item a, Item b)
{
    return a.value / (a.weight * 1.0) > b.value / (b.weight * 1.0);
}
double fractionalKnapsack(int w, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    int i;
    double sum = 0.0;

    for (i = 0; i < n; i++)
    {
        if (w - arr[i].weight >= 0)
        {
            sum += arr[i].value;
            w -= arr[i].weight;
        }
        else
        {
            sum += w * (arr[i].value / (arr[i].weight * 1.0));
            break;
        }
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        Item arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }
        cout << fixed << setprecision(2) << fractionalKnapsack(w, arr, n) << endl;
    }
    return 0;
}