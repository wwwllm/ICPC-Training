#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2038/A
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<int> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = a[i] / b[i];
        suf[i] = suf[i + 1] + cnt;
    }
    for (int i = 0; i < n; i++)
    {
        int sum = suf[i];
        if (sum < k)
            c[i] = 0;
        else
        {
            sum -= a[i] / b[i];
            c[i] = max(0LL, k - sum);
            k -= c[i];
        }
    }
    for (auto it : c)
        cout << it << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}