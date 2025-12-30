#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int a[N], d[N];
void solve()
{
    int n, q, p;
    cin >> n >> p >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        d[i] = a[i] - a[i - 1];
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, v;
        cin >> l >> r >> v;
        d[l] += v;
        d[r + 1] -= v;
    }
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + d[i], p = max(a[i], p);
    if (p >= q)
        cout << "3G win win!" << endl;
    else
        cout << "3G wanna win win" << endl;
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