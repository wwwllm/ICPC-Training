#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{

    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int dep = __lg(x);
        int l = 1LL << dep, r = min(n, (1LL << (dep + 1)) - 1);
        cout << r - l + 1 << '\n';
    }
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