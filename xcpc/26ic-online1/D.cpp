#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int x = 0, y = 0;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (x == y)
            (ans *= 2) %= mod;
        if (cnt[x])
            cnt[x]--,y++;
        else if (cnt[y])
            cnt[y]--,x++;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}