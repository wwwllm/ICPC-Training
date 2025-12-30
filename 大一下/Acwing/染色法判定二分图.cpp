#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, m;
vector<int> g[maxn];
int color[maxn]; // 0表示未染色
bool dfs(int u, int c)
{
    color[u] = c;
    for (auto ele : g[u])
    {
        if (!color[ele])
        {
            if (!dfs(ele, 3 - c))
                return 0;
        }
        else if (color[ele] == c)
            return 0;
    }
    return 1;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    };
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}