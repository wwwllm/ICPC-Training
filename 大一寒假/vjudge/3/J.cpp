#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 50;
vector<int> tr[maxn];
int du[maxn], ans[maxn];
int dfs(int i, int fu)
{
    if (du[i] == 1 && i != 1)
    {
        ans[i] = 1;
        return ans[i];
    }
    for (auto it : tr[i])
    {
        if (it == fu)
            continue;
        else
        {
            ans[i] += dfs(it, i);
        }
    }
    return ans[i];
}
void solve()
{
    int n, q;
    cin >> n;
    memset(du, 0, sizeof(du));
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
        tr[i].clear();
    for (int i = 1; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        tr[l].push_back(r);
        tr[r].push_back(l);
        du[l]++, du[r]++;
    }
    dfs(1, 1);
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << ans[x] * ans[y] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
