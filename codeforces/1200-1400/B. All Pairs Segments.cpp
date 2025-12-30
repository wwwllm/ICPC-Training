#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2019/B
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &X : a)
        cin >> X;
    map<int, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int cnt = (n - i - 1) * (i + 1);
        if (i == 0)
        {
            if (i + 1 == n - 1)
                mp[cnt] += a[i + 1] - a[i] + 1;
            else
            {
                int res = (n - i - 2);
                mp[res + cnt]++;
                mp[cnt] += a[i + 1] - a[i];
            }
        }
        else
        {
            if (i + 1 == n - 1)
            {
                mp[cnt] += a[i + 1] - a[i];
            }
            else
            {
                int res = (n - i - 2);
                mp[res + cnt]++;
                mp[cnt] += a[i + 1] - a[i] - 1;
            }
        }
    }
    while (q--)
    {
        int k;
        cin >> k;
        if (mp.find(k) == mp.end())
            cout << 0 << ' ';
        else
            cout << mp[k] << ' ';
    }
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