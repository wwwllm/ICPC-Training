#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> g[N];
int d = 0;
int ans[N];
bool h_f[N];
int top = 0;
bool dfs(int u)
{
    ans[++top] = u;
    bool flag = 1;
    int len = g[u].size();
    if (len != d && len != 0)
        flag = 0;
    for (auto it : g[u])
        flag = flag & dfs(it);
    return flag;
}
signed main()
{
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        int f;
        cin >> f;
        if (f == 0)
        {
            root = i;
            continue;
        }
        g[f].push_back(i);
        d = max(d, (int)g[f].size());
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    if (dfs(root))
    {
        cout << d << " yes" << endl;
        cout << ans[1];
        for (int i = 2; i <= n; i++)
            cout << ' ' << ans[i];
    }
    else
    {
        cout << d << " no" << endl;
        cout << ans[1];
        for (int i = 2; i <= n; i++)
            cout << ' ' << ans[i];
    }
    return 0;
}