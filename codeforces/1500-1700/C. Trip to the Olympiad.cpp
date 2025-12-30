#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2057/C
void solve()
{
    int l, r;
    cin >> l >> r;
    for (int i = 32; i >= 0; i--)
    {
        if (((l >> i) & 1) != ((r >> i) & 1))
        {
            int a = ((l >> i) << i) + (1LL << i);
            int b = a - 1;
            int c = b == l ? r : l;
            cout << a << ' ' << b << ' ' << c << '\n';
            return;
        }
    }
    cout << l << " " << l << ' ' << l << '\n';
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
