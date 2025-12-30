#include <bits/stdc++.h>
using namespace std;

const int inf = 1e5;
void solve()
{
    cout << "? 100000";
    for (int i = 1; i <= 1e5; i++)
        cout << " 1";
    cout << endl;
    int len;
    cin >> len;
    if (len == 1)
    {
        cout << "! 100000" << endl;
        return;
    }
    int l = inf / len;
    int r = inf % (len - 1) == 0 ? inf / (len - 1) - 1 : inf / (len - 1);
    cout << "? " << (r - l + 1) * 2 - 1 << ' ' << l << ' ';
    for (int i = l + 1; i <= r; i++)
    {
        cout << l << ' ' << i - l << ' ';
    }
    cout << endl;
    int m;
    cin >> m;
    int cnt = m - (r - l + 1);
    int ans = r - cnt;
    cout << "! " << ans << endl;
    cout.flush();
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