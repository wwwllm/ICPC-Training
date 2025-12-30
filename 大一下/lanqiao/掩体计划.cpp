#include <bits/stdc++.h>
// #define int long long
using namespace std;

const int maxn = 1e5 + 50;
vector<int> tr[maxn];
int ans = 1e5 + 50;
bool b[maxn];
void dfs(int u, int f, int cnt)
{
    bool flag = 1;
    for (auto v : tr[u])
    {
        if (v == f)
            continue;
        if (tr[u].size() > 2 || u == 1 && tr[u].size() > 1)
            dfs(v, u, cnt + 1);
        else
            dfs(v, u, cnt);
        flag &= b[v];
    }
    if (tr[u].size() > 2 || u == 1 && tr[u].size() > 1)
        b[u] = flag;
    if (b[u])
        ans = min(ans, cnt);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    int m;
    cin >> m;
    while (m--)
    {
        int u;
        cin >> u, b[u] = 1;
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}