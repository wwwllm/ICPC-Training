#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    if(m>r)
        cout << r - m << ' ' << r << endl;
    else
        cout << 0 << ' ' << m << endl;
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