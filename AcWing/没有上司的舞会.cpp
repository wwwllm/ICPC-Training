#include <bits/stdc++.h>
using namespace std;

const int N = 6050;
int n;
int v[N], dp[N][2];
bool is_root[N];
vector<int> g[N];
void dfs(int u)
{
    dp[u][1] = v[u];
    for (auto ele : g[u])
    {
        dfs(ele);
        dp[u][1] += dp[ele][0];
        dp[u][0] += max(dp[ele][1], dp[ele][0]);
    }
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        is_root[a] = 1;
    }
    int root = -1;
    for (int i = 1; i <= n; i++)
        if (!is_root[i])
            root = i, dfs(i);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}