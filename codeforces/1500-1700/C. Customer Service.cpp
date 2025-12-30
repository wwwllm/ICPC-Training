#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2059/C
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    multiset<int> s;
    for (int i = 1; i <= n;i++){
        int res = 0;
        for (int j = n; j >= 1;j--){
            if(g[i][j]==1)res++;
            else
                break;
        }
        s.insert(res);
    }
    int ans = 0;
    while(s.size()){
        int x=*s.begin();
        if(x>=ans)ans++;
        s.erase(s.find(x));
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}