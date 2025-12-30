#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2063/C
void solve()
{
    int n;
    cin >> n;
    vector<set<int>> g(n + 1);
    vector<array<int, 2>> d(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        d[u][0]++, d[v][0]++;
    }
    for (int i = 1; i <= n; i++)
        d[i][1] = i;
    sort(d.begin() + 1, d.end());
    int cnt = 0, i;
    for (i = n; i >= 0; i--)
    {
        if (d[i][0] == d[n][0])
            cnt++;
        else
            break;
    }
    if (cnt >= 3)
    {
        cout << 2 * d[n][0] - 1 << '\n';
    }
    else if (cnt == 2)
    {
        int u = d[n][1], v = d[n - 1][1];
        if (g[u].find(v) == g[u].end())
            cout << d[n][0] * 2 - 1 << '\n';
        else
            cout << d[n][0] * 2 - 2 << '\n';
    }
    else{
        int u = d[n][1];
        for(int j=i;j>=0;j--){
            if(d[j][0]==d[i][0]&&g[u].find(d[j][1])==g[u].end()){
                cout << d[n][0] + d[j][0] - 1 << '\n';
                return;
            }
            if(d[j][0]!=d[i][0])
                break;
        }
        cout << d[n][0] + d[i][0] - 2 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}