#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &X : a)
        cin >> X;
    vector<int> bit(64);
    for (auto x : a)
    {
        for (int i = 0; i < 64; i++)
        {
            bit[i] += (x >> i) & 1;
        }
    }
    for (int i = 0; i < 64; i++)
    {
        int tmp = (1LL << i);
        if (k >= tmp * (n - bit[i]))
        {
            k -= tmp * (n - bit[i]);
            bit[i] = n;
        }
        else if (k >= tmp)
        {
            bit[i] += k / tmp;
            k %= tmp;
            break;
        }
        else
            break;
    }
    int ans = 0;
    for (auto cnt : bit)
        ans += cnt;
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