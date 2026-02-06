#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    if (l == 0)
    {
        cout << r + 1 << '\n';
        return;
    }
    int lenl = 63LL - __builtin_clzll(l), lenr = 63LL - __builtin_clzll(r);
    if (lenl == lenr)
    {
        cout << 0 << '\n';
        return;
    }
    if (lenr > lenl + 1)
    {
        cout << r + 1 << '\n';
        return;
    }
    for (int k = lenl; k >= 0; k--)
    {
        if (!((l >> k) & 1))
        {
            l = (l >> k) << k;
            break;
        }
    }
    int ma = r - (1LL << lenr) + 1;
    if (ma >= l)
        cout << r + 1 << '\n';
    else
        cout << ma << '\n';
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