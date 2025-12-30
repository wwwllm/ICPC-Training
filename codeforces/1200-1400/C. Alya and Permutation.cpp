#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2035/C
void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << n << '\n';
        for (int i = 2; i < n - 1; i++)
            cout << i << ' ';
        cout << 1 << ' ' << n - 1 << ' ' << n << '\n';
    }
    else
    {
        int k = n, cnt = 0;
        while (k)
        {
            k >>= 1;
            cnt++;
        }
        cout << (1LL << cnt) - 1 << '\n';
        int a = (1LL << (cnt - 1)) - 1;
        int b = a - 1;
        for (int i = 2; i < n; i++)
        {
            if (i != a && i != b)
                cout << i << ' ';
        }
        cout << 1 << ' ' << b << ' ' << a << ' ' << n << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}