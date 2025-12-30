#include <bits/stdc++.h>
#define ll long long
using namespace std;

//(x+k)&(y+k)==0;
void solve()
{
    ll x, y;
    cin >> x >> y;
    if(x==y)
        cout << -1 << endl;
    else
        cout << (1ll << 59) - max(x,y) << endl;
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