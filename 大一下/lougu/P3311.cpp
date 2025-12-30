#include <bits/stdc++.h>
using namespace std;

const int N = 2020, mod = 1e9 + 7;
int tr[N][10], fi[N], ed[N], idx, cnt[N];
bool alert[N];
int dp[N][N][2][2];
int n, m;
string num;
void insert(string str)
{
    int p = 0;
    for (auto ele : str)
    {
        int u = ele - '0';
        if (!tr[p][u])
            tr[p][u] = ++idx;
        p = tr[p][u];
    }
    alert[p] = 1;
}
void setfile()
{
    queue<int> q;
    for (int i = 0; i < 10; i++)
        if (tr[0][i])
            q.push(tr[0][i]);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 10; i++)
            if (tr[u][i])
                fi[tr[u][i]] = tr[fi[u]][i], q.push(tr[u][i]);
            else
                tr[u][i] = tr[fi[u]][i];
        alert[u] |= alert[fi[u]];
    }
}
// has:表示选过数没有
// free:表示能不能选0-9任意数
int dfs(int i, int j, int free, int has)
{
    if (alert[j])
        return 0;
    if (dp[i][j][free][has] != -1)
        return dp[i][j][free][has];
    if (i == n)
        return has;
    int ans = 0;
    int cur = num[i] - '0';
    if (!has)
    {
        if (!free)
        {
            ans = (ans + dfs(i + 1, 0, 1, 0)) % mod;
            for (int k = 1; k < cur; k++)
                ans = (ans + dfs(i + 1, tr[j][k], 1, 1)) % mod;
            ans = (ans + dfs(i + 1, tr[j][cur], 0, 1)) % mod;
        }
        else
        {
            ans = (ans + dfs(i + 1, 0, 1, 0)) % mod;
            for (int k = 1; k <= 9; k++)
                ans = (ans + dfs(i + 1, tr[j][k], 1, 1)) % mod;
        }
    }
    else
    {
        if (!free)
        {
            for (int k = 0; k < cur; k++)
                ans = (ans + dfs(i + 1, tr[j][k], 1, 1)) % mod;
            ans = (ans + dfs(i + 1, tr[j][cur], 0, 1)) % mod;
        }
        else
        {
            for (int k = 0; k <= 9; k++)
                ans = (ans + dfs(i + 1, tr[j][k], 1, 1)) % mod;
        }
    }
    return dp[i][j][free][has] = ans;
}
signed main()
{
    cin >> num >> m;
    n = num.length();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    setfile();
    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}