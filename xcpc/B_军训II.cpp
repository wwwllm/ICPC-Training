#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
vector<int> p(N + 1);
void init()
{
    p[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * i % mod;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "0 1\n";
        return;
    }
    ranges::sort(a);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ans += a[j] - a[i];
        }
    }
    int cnt = 2;
    if (a[0] == a.back())
        cnt = 1;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && a[j] == a[i])
            j++;
        int len = j - i;
        cnt = cnt * p[len] % mod;
        i = j - 1;
    }
    cout << ans << ' ' << cnt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}