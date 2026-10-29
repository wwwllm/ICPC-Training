#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int s[N];
vector<int> g[N];
int dfs(int u, int flag)
{
    int ans = s[u];
    if (g[u].empty())
        return ans;
    if (flag)
    {
        int v, w = -INF;
        for (auto it : g[u])
            if (s[it] > w)
                v = it, w = s[it];
        ans += dfs(v, !flag);
    }else{
        int v, w = INF;
        for (auto it : g[u])
            if (s[it] < w)
                v = it, w = s[it];
        ans += dfs(v, !flag);
    }
    return ans;
}
signed main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    cout << dfs(1, 1) + k << endl;
    return 0;
}