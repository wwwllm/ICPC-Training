#include <bits/stdc++.h>
#define int long long
using namespace std;

using i128 = __int128;
const int inf = 2e18;
int mul(int x, int y)
{
    return std::min<i128>((i128)x * y, inf);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector C(n + 1, vector<int>(n + 1));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = min(inf, C[i - 1][j - 1] + C[i - 1][j]);
        }
    }
    vector<int> e(n + 1);
    e[0] = e[1] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 2; i <= len; i += 2)
        {
            int tmp = mul(C[len - 1][i - 1], e[i - 1]);
            tmp = mul(tmp, e[len - i]);
            e[len] += tmp;
            e[len] = min(e[len], inf);
        }
    }
    vector<int> vis(n + 1), ans(n + 1);
    auto check = [&](int u, int op) -> bool
    {
        if (u % 2 == op)
            return 1;
        if (u > 1 && !vis[u - 1])
            return 0;
        if (u < n && !vis[u + 1])
            return 0;
        return 1;
    };
    auto calc = [&]() -> int
    {
        int ans = 1;
        int sum = 0;
        for (int i = 1; i <= n;)
        {
            if (!vis[i])
            {
                int j = i;
                while (j <= n && !vis[j])
                    j++;

                int len = j - i;
                sum += len;
                ans = mul(ans, e[len]);
                ans = mul(ans, C[sum][len]);

                i = j;
            }
            else
                i++;
        }
        return ans;
    };

    int cur = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[j])
                continue;
            int tmp = cur;
            if (tmp == -1)
            {
                tmp = j % 2;
            }
            if (!check(j, tmp))
                continue;
            vis[j] = 1;
            int res = calc();
            if (res >= k)
            {
                ans[i] = j;
                cur = tmp;
                break;
            }
            else
            {
                k -= res;
                vis[j] = 0;
            }
        }
        if (ans[i] == 0)
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}