#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;
int a[maxn];
void solve1(int l, int r, int x)
{
    int i = l - 1, j = r + 1, mid;
    while (i + 1 != j)
    {
        mid = (i + j) >> 1;
        if (a[mid] < x)
            i = mid;
        else
            j = mid;
    }
    if ( a[j]!=x)
        cout << -1;
    else
        cout << j-1;
}
void solve2(int l, int r, int x)
{
    int i = l - 1, j = r + 1, mid;
    while (i + 1 != j)
    {
        mid = (i + j) >> 1;
        if (a[mid] <= x)
            i = mid;
        else
            j = mid;
    }
    if (a[i]!=x)
        cout << -1;
    else
        cout << i-1;
}
int main()
{
    int n,q;
    cin >> n>>q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        int x;
        cin >> x;
        solve1(1, n, x);
        cout << ' ';
        solve2(1, n, x);
        cout << endl;
    }
    return 0;
}