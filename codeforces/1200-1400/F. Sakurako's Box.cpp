#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2008/F
const int mod = 1e9 + 7;
int ex_power(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), suf(n + 1, 0);
    for (auto &x : a)
        cin >> x;
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = (suf[i + 1] + a[i]) % mod;
    }
    int p = 0, q = 0;
    for (int i = 0; i < n; i++)
    {
        p = (p + a[i] * suf[i + 1]) % mod;
        q = (q + i) % mod;
    }
    cout << p * ex_power(q, mod - 2) % mod << '\n';
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