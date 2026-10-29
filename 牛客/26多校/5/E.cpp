#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7, mod = 998244353;
vector<int> cnt(N + 1);
vector<int> prime;
void init()
{
    for (int i = 2; i <= N; i++)
    {
        if (cnt[i] == 0)
        {
            cnt[i] = 1;
            prime.push_back(i);
        }
        for (auto p : prime)
        {
            if (i * p > N)
                break;
            cnt[i * p] = cnt[i] + 1;
            if (i % p == 0)
                break;
        }
    }
}
void solve()
{
    int n, c;
    cin >> n >> c;
    int ans = 0;
    int cur = c;
    for (int i = 1; i <= n; i++)
    {
        int g;
        if (i == 1 || cnt[i] == 1)
            g = 1;
        else
            g = prime[cnt[i] - 2];
        (ans += cur * g % mod) %= mod;
        (cur *= c) %= mod;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}