#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;
int ans[maxn];
vector<int> p[maxn];
void dfs(int x)
{
    for (auto ele : p[x])
    {
        if (!ans[ele])
            ans[ele] = 1,
            dfs(ele);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        p[y].push_back(x);
    }
    if(p[1].empty())
        ans[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
