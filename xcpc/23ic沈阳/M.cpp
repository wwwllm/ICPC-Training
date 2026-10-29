#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6, mod = 1e9 + 7;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return ans;
}
void solve()
{
    int k;
    string a, b;
    cin >> a >> b >> k;
    int n = max(a.size(), b.size());
    ranges::reverse(a);
    ranges::reverse(b);
    a.resize(n, '0');
    b.resize(n, '0');
    vector<int> t(n + 4);
    for (int i = 0; i < n; i++)
    {
        t[i] = (a[i] - '0') ^ (b[i] - '0');
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i])
            break;
        else
            cnt++;
    }
    vector<int> T = {0, 1, 3, 2};
    int cur = 0;
    int s1 = 0;
    for (int i = 0; i < (n | 1); i += 2)
    {
        int u = t[i] + t[i + 1] * 2;
        s1 += T[u] * (cur + 1) % mod;
        cur = (cur * 4 + 4) % mod;
        cur %= mod;
        s1 %= mod;
    }

    int r = cnt / 2 + 1;
    if (r < k && a != b)
    {
        cout << -1 << '\n';
        return;
    }
    int r1 = (exp(4, k) + mod - 1) * (exp(3, mod - 2)) % mod + mod - 1;
    r1 %= mod;
    cout << (s1 + r1) % mod << '\n';
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