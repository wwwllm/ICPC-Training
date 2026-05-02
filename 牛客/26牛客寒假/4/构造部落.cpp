#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, q, s;
    cin >> n >> q >> s;
    vector<int> t(n + 1);
    t[0] = s;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    vector<int> pre(n + 1);
    pre[0] = s;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + t[i];
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << pre[x - 1] + y - 1 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}