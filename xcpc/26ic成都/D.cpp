#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, ha, hb;
    cin >> a >> b >> ha >> hb;
    int ca = (ha + b - 1) / b, cb = (hb + a - 1) / a;
    if((ca-cb)>3){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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