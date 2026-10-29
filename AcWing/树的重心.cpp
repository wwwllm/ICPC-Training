#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, INF = 0x3f3f3f3f;
int n, ans = INF;
bool st[maxn];
vector<int> g[maxn];
int dfs(int u)
{
    st[u] = 1;
    int sum = 1, res = 0;
    for (auto ele : g[u])
    {
        if (!st[ele])
        {
            int s = dfs(ele);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(n - sum, res);
    ans = min(res, ans);
    return sum;
}
signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    st[1] = 1;
    dfs(1);
    cout << ans << endl;
    return 0;
}