#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5, mod = 998244353;
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
    vector<int> b(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ranges::sort(a, greater<int>());
    int mi = *ranges::min_element(b);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mi)
            cnt++;
    }
    int ans = p[cnt] * p[n - cnt] % mod;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}