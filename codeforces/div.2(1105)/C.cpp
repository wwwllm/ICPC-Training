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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] ^ a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] ^ a[i];
    }
    if (pre[n] == 0)
    {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((pre[i - 1] ^ suf[i + 1]) <= a[i])
            ans++;
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