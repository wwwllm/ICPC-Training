#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, k;
bool vis[N];
bool cmp(int x)
{
    int ans = 0;
    int mex = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= n + 1)
            vis[a[i]] = 1;
        while (vis[mex])
            mex++;
        if (mex >= x)
        {
            ans++;
            mex = 0;
            for (int i = 0; i <= min(x + 1, n + 2); i++)
                vis[i] = 0;
        }
    }
    for (int i = 0; i <= n + 1; i++)
        vis[i] = 0;
    return ans >= k;
}
void solve()
{
    cin >> n >> k;
    int maxa = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = -1, r =n+1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (cmp(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
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