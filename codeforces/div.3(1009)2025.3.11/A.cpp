#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if(l==r&&l==d&&l==u)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
