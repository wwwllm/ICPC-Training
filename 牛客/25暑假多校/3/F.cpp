#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int t = a + b;
    int k = n % t;
    if (k == 0 || k > a)
    {
        cout << 0 << '\n';
    }
    else
    {
        int ans = k;
        if (ans < n)
            cout << ans << '\n';
        else
            cout << "Sayonara\n";
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