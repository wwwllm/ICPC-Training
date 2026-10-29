#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int k;
    cin >> k;
    int len = 1;
    while (len * (len + 1) / 2 <= k)
    {
        len++;
    }
    int r = k - len * (len - 1) / 2;
    cout << len + r << ' ' << 2 << '\n';
    for (int i = 1; i <= len; i++)
        cout << 'a';
    for (int i = 1; i <= r; i++)
        cout << 'b';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    // init();
    while (t--)
        solve();
    return 0;
}
