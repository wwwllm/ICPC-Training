#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int res = n - 1;
    if (n > 2)
    {
        int d = (n - 2) / 5, r = (n - 2) % 5;
        res += d;
        if (r >= 3)
            res++;
    }
    cout << res << '\n';
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