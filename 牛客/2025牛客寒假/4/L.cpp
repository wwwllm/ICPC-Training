#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<vector<int>> prea(n + 1, vector<int>(32)), preb(n + 1, vector<int>(32));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            prea[i][j] = prea[i - 1][j] + ((a[i] >> j) & 1);
            preb[i][j] = preb[i - 1][j] + ((b[i] >> j) & 1);
        }
    }
    auto query = [&](int l1, int l2, int r1, int r2) -> int
    {
        if (r1 > r2)
            return 0LL;
        int res = 0;
        for (int j = 0; j < 32; j++)
        {
            res += (prea[l2][j] - prea[l1 - 1][j]) * (r2 - r1 + 1 - preb[r2][j] + preb[r1 - 1][j]) << j;
            res %= mod;
            res += (l2 - l1 + 1 - (prea[l2][j] - prea[l1 - 1][j])) * (preb[r2][j] - preb[r1 - 1][j]) << j;
            res %= mod;
        }
        return res % mod;
    };
    vector<int> pred(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 0; j < 32; j++)
        {
            res = ((a[i] >> j) & 1) ? res + ((n - i + 1 - preb[n][j] + preb[i - 1][j]) << j) : res + ((preb[n][j] - preb[i - 1][j]) << j);
        }
        pred[i] = pred[i - 1] + res;
        pred[i] %= mod;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ((pred[r] - pred[l - 1] + mod) % mod - query(l, r, r + 1, n) + mod) % mod << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}