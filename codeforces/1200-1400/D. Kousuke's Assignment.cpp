#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2033/D
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), pre(n);
    for (auto &x : a)
        cin >> x;
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    set<int> S;
    S.insert(0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 || S.find(pre[i]) != S.end())
        {
            S.clear();
            ans++;
        }
        S.insert(pre[i]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}