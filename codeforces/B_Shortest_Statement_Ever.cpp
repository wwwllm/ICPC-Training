#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// https://codeforces.com/problemset/problem/2187/B
const int inf = 1e18;
void solve()
{
    int x, y;
    cin >> x >> y;
    int mi = x + y;
    int p = 0, q = 0;
    auto update = [&](int P, int Q)
    {
        if ((P & Q) == 0 && abs(P - x) + abs(Q - y) < mi)
        {
            p = P, q = Q;
            mi = abs(P - x) + abs(Q - y);
        }
    };
    update(x, y);
    for (int i = 30; i >= 0; i--)
    {
        if (((x & y) >> i) & 1)
        {
            update((x >> i << i) + (1LL << i), y);
            update(x, (y >> i << i) + (1LL << i));
            update(x >> i << i, (y >> i << i) - 1);
            update((x >> i << i) - 1, y >> i << i);
        }
    }
    cout << p << ' ' << q << '\n';
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