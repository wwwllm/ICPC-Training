#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
void solve()
{
    int m, k;
    cin >> m >> k;

    auto check = [&](int x, int m) -> bool {
        
    };
    int l = 0, r = 1e18;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid, m))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
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