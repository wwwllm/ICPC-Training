#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n = 0;
    array<int, 3> c;
    for (int i = 0; i < 3; i++)
    {
        cin >> c[i];
        n += c[i];
    }
    int len = 3 * n;
    int cnt1 = min(c[0], c[2]);
    len -= 2 * cnt1;
    c[0] -= cnt1;
    cnt1 = min(c[0], c[1] * 2);
    len -= cnt1;
    c[0] -= cnt1;
    len -= max(0LL, c[0] - 1);
    cout << len << '\n';
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