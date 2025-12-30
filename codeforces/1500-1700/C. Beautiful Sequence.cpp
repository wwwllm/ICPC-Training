#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2069/C
const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &X : a)
        cin >> X;
    int ans = 0, cnt = 0, res = 0;
    bool ok = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 3)
            cnt++, res = (res + 1) % mod;
        else if (a[i] == 1)
            ans = (ans + res - cnt + mod) % mod;
        else
            res = (res * 2) % mod;
    }
    cout << ans << '\n';
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