#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105358
void solve()
{
    int n;
    cin >> n;
    int cur = 1500;
    for (int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;
        cur += d;
        if (cur >= 4000)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}