#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2028/B
void solve()
{
    int n, b, c;
    cin >> n >> b >> c;
    if (b == 0)
    {
        if (n - c >= 3)
            cout << -1 << '\n';
        else if (c >= n)
            cout << n << '\n';
        else
            cout << n - 1 << '\n';
    }
    else
    {
        int cnt = max(0LL, (n - c + b - 1) / b);
        cout << n - cnt << '\n';
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