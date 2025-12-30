#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, s, t;
    cin >> n >> k >> s >> t;
    if (!(k & 1) && (s & 1) != (t & 1))
    {
        cout << -1 << '\n';
        return;
    }
    if (k == n)
    {
        if (s == t)
            cout << 0 << '\n';
        else if (t == n - s)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
        return;
    }
    else
    {
        int d = abs(s - t);
        int m = (d + k - 1) / k;
        while((m*k-d)%2!=0){
            
        }
        cout << ans << '\n';
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