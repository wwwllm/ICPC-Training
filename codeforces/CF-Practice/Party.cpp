#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2005;
int f[maxn];
int dfs(int x,int d){
    if(f[x]==-1)
        return d;
    return dfs(f[x], d + 1);
}
void solve()
{
    int n,ans=0;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> f[i];
    }
    for (int i = 1; i <= n;i++){
        ans = max(ans, dfs(i, 1));
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t=1;
 //   cin >> t;
    while (t--)
        solve();
    return 0;
}