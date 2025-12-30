#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n, k;
int idx, a[N];
void solve()
{
    cin >> n >> k;
    vector<array<int, 2>> son(33 * n, {0,0});
    vector<int> ed(33 * n, 0);
    auto insert = [&](int x, int pos)
    {
        int p = 0;
        for (int i = 31; i >= 0; i--)
        {
            int u = (x >> i) & 1;
            if (!son[p][u])
                son[p][u] = ++idx;
            p = son[p][u];
            ed[p] = max(ed[p], pos);
        }
    };
    auto query = [&](int x, int pos)
    {
        int ans = INF, p = 0;
        for (int i = 31; i >= 0; i--)
        {
            int xi = (x >> i) & 1, ki = (k >> i) & 1;
            if (ki)
            {
                if (son[p][!xi])
                    p = son[p][!xi];
                else
                    return ans;
            }
            else
            {
                if (son[p][!xi])
                    ans = min(ans, pos - ed[son[p][!xi]] + 1);
                if (son[p][xi])
                    p = son[p][xi];
                else
                    return ans;
            }
        }
        ans = min(ans, pos - ed[p] + 1);
        return ans;
    };
    int ans = INF;
    idx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i], i);
        ans = min(ans, query(a[i], i));
    }
    if (ans <=n)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}