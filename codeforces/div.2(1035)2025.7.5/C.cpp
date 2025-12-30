#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n & 1)
    {
        cout << l << '\n';
        return;
    }
    if (n == 2)
    {
        cout << -1 << '\n';
        return;
    }
    else
    {
        int p = 0;
        while (l >= (1LL << p))
            p++;
        if ((1LL << p) > r)
        {
            cout << -1 << '\n';
        }
        else
        {
            if (k >= n - 1)
            {
                cout << (1LL << p) << '\n';
            }
            else
                cout << l << '\n';
        }
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
};