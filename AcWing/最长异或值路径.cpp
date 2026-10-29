#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef pair<int, int> PII;
vector<PII> g[N];
int n, a[N];
bool h_f[N];
int son[N * 32][2], idx;
void dfs(int u, int res)
{
    a[u] = res;
    for (auto [s, v] : g[u])
    {
        dfs(s, res ^ v);
    }
}
void insert(int x)
{
    int p = 0;
    for (int i = 31; i >= 0; i--)
    {
        int u = (x >> i) & 1;
        if (!son[p][u])
        {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
}
int query(int x)
{
    int p = 0, ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int u = (x >> i) & 1;
        if (son[p][!u])
        {
            ans = ans * 2 + !u;
            p = son[p][!u];
        }
        else
        {
            ans = ans * 2 + u;
            p = son[p][u];
        }
    }
    return ans ^ x;
}
signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        g[a].push_back({b, v});
        h_f[b] = 1;
    }
    for (int i = 0; i < n; i++)
        if (!h_f[i])
            dfs(i, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
        insert(a[i]);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, query(a[i]));
    }
    cout << ans << endl;
    return 0;
}