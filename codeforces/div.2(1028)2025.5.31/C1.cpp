#include <bits/stdc++.h>
#define int long long
using namespace std;

// C题dp解法

const int N = 5000;
const int INF = 1e9;
int G[N + 1][N + 1];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &X : a)
        cin >> X;
    int cnt = 0;
    int g = a[0];
    for (auto it : a)
        g = gcd(g, it);
    for (auto it : a)
    {
        if (it == g)
        {
            cnt++;
        }
    }
    if (cnt != 0)
    {
        cout << n - cnt << '\n';
        return;
    }
    vector<int> dp(N + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x <= N; x++)
        {
            int y = G[a[i]][x];
            dp[y] = min(dp[y], dp[x] + 1);
        }
    }
    cout << dp[g] + n - 2 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            G[i][j] = gcd(i, j);
    while (t--)
        solve();
    return 0;
}