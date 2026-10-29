#include <bits/stdc++.h>
#define int long long
using namespace std;

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> st(n + 1, 0);
    int res = 0;
    auto dfs = [&](int u) -> int
    {
        int len = 0;
        while (!st[u])
        {
            st[u] = 1;
            len++;
            u = a[u];
        }
        return len;
    };
    vector<int> len0, len1;
    int mul = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            int len = dfs(i);
            if (len & 1)
                len1.push_back(len);
            else
            {
                len0.push_back(len);
                if (len > 2)
                    mul = (mul * 2) % mod;
            }
        }
    }
    if (!len1.size())
    {
        for (auto x : len0)
        {
            int tmp = (x / 2 * x / 2) % mod;
            if (x > 2)
                tmp = tmp * exp(2, mod - 2) % mod;
            res = (res + tmp) % mod;
        }
        res = res * mul % mod;
        cout << res << '\n';
    }
    else if (len1.size() == 2)
    {
        int ans = 1;
        for (auto x : len1)
            ans = (ans * x) % mod;
        ans = ans * mul % mod;
        cout << ans << '\n';
    }
    else
        cout << 0 << '\n';
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