#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int bcj[maxn], v[maxn], n, dp[maxn][2];
vector<int> g[maxn];
int ans = 0;
int find(int x)
{
    return bcj[x] == x ? x : find(bcj[x]);
}
void join(int a, int b)
{
    int ra = find(a), rb = find(b);
    if (ra != rb)
        bcj[rb] = ra;
}
void dfs(int u,int fa)
{
    dp[u][1] = v[u];
    for (auto ele : g[u])
    {
        if(ele==fa)
            continue;
        dfs(ele,u);
        dp[u][0] += max(dp[ele][0], dp[ele][1]);
        dp[u][1] += dp[ele][0];
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i], bcj[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int len;
        cin >> len;
        while (len--)
        {
            int x;
            cin >> x;
            g[i].push_back(x);
            join(i, x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (bcj[i] == i)
        {
            dfs(i,0);
            ans += max(dp[i][0], dp[i][1]);
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin>>t;
    while (t--)
        solve();
    return 0;
}