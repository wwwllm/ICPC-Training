#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;
        mp[u]++;
    }
    int ans = 0;
    int sum = 1;
    int c = 1;
    for (auto [x, cnt] : mp)
    {
        (sum *= exp(2, cnt - 1)) %= mod;
        if (mp.count(-1) && mp.count(x - 1))
        {
            c++;
        }
    }
    ans = (c * sum) % mod;
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