#include <bits/stdc++.h>
using namespace std;
bool isvalid(int A[], int N, int M, int mid)
{
    long long student = 1;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum > mid)
        {
            student++;
            sum = A[i];
        }
        if (student > M)
        {
            return false;
        }
    }
    return true;
}
long long findPages(int A[], int N, int M)
{
    long long s = *max_element(A, A + N);
    long long e = 0;

    for (long i = 0; i < N; i++)
        e += A[i];

    long res = -1;

    if (N < M)
    {
        return -1;
    }
    while (s <= e)
    {
        long long mid = s + (e - s) / 2;

        if (isvalid(A, N, M, mid) == true)
        {
            res = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int M;
        cin >> M;
        cout << findPages(A, N, M) << endl;
    }
    return 0;
}