#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2072/F
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cout << (((i & (n - 1) )== i ? k: 0)) << ' ';
    cout << '\n';
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