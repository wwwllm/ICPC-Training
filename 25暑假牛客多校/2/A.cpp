#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, N = 5e5 + 10;
vector<int> p2(N + 1);
void init()
{
    p2[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p2[i] = (p2[i - 1] * 2) % mod;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += (a[i] == -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 || a[i + 1] == 0)
            continue;
        int cnt = (a[i] == -1) + (a[i + 1] == -1);
        ans = (ans + p2[sum - cnt]) % mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}