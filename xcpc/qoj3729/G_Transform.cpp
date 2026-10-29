#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
const int mod = 998244353, inf = 1e9;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = a * ans % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mex = 0;
    ranges::sort(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mex)
        {
            mex++;
        }
    }
    if (n == 1 && a[0] == k)
    {
        cout << 0 << '\n';
        return;
    }
    if (mex == k)
    {
        cout << 1 << '\n';
        return;
    }
    else if (mex > k)
    {
        cout << 2 << '\n';
        return;
    }
    map<int, int, greater<int>> mp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < k)
            mp[a[i]]++;
    }
    int cnt = 1;
    int pre = k - 1;
    int res = 0;
    if (mp.find(0) == mp.end())
        mp[0] = 0;
    for (auto [x, c] : mp)
    {
        int len = pre - x;
        if (len > 0)
        {
            if (len > 32)
                cnt = inf;
            else
                cnt = min(inf, cnt * (1LL << len));
        }
        int can = min(cnt, c);
        (res += can % mod * exp(2, x) % mod) %= mod;
        cnt = min(inf, cnt + cnt - can);
        pre = x - 1;
    }
    cout << (exp(2, k) - res + mod) % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}