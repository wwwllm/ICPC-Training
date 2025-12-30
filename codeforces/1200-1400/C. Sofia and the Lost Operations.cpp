#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/1980/C
void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &X : a)
        cin >> X;
    for (auto &X : b)
        cin >> X;
    cin >> m;
    bool ok = 1;
    vector<int> d(m);
    map<int, int> mp;
    for (auto &x : d)
    {
        cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (mp[b[i]] > 0)
                mp[b[i]]--;
            else
                ok = 0;
        }
    }
    if (ok == 0)
    {
        cout << "NO\n";
        return;
    }
    int c = d.back();
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (c == b[i])
            flag = 1;
    }
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
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