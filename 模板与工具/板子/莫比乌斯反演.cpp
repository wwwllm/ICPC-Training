#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7;
vector<int> vis(N + 1), prime, mu(N + 1);
void init()
{
    mu[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (auto p : prime)
        {
            if (i * p > N)
                break;
            vis[i * p] = 1;
            if (i % p == 0)
            {
                mu[i * p] = 0;
            }
            mu[i * p] = mu[i] * mu[p];
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int d = 1; d <= min(n, m); d++)
    {
        ans += (n / d) * (m / d);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}