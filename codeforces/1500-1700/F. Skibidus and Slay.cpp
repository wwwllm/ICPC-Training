#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2065/F
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> ans(n + 1);
    for(int u=1;u<=n;u++){
        map<int,int>mp;
        for(auto v:g[u]){
            mp[a[v]]++;
        }
        mp[a[u]]++;
        for(auto [x,cnt]:mp){
            if(cnt>=2)
                ans[x] = 1;
        }
    }
    for(int i=1;i<=n;i++)
        cout << ans[i] ;
    cout << '\n';
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