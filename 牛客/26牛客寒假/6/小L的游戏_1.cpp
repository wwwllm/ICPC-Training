#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int m, n, z;
    cin >> n >> m >> z;
    int r = z % (n + m);
    if (r > n || r == 0)
        cout << 1;
    else
        cout << 0;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}