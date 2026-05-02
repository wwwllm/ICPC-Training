#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    if ((sum & 1) || !((k * n) & 1))
        cout << "YES\n";
    else
        cout << "NO\n";
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