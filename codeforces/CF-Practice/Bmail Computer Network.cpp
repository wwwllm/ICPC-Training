#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5 + 50;
int p[maxn], ans[maxn], top = 0;
void dfs(int n)
{
    if (n==1)
    {
        ans[++top] = n;
        return;
    }
    ans[++top] = n;
    dfs(p[n]);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
    }
    dfs(n);
    for (int i = top; i >= 1;i--){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin >> t;
    while (t--)
        solve();
    return 0;
}