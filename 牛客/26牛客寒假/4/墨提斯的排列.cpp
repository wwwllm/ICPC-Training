#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a = {0, 1};
    int p = 2;
    n--;
    while (n--)
    {
        auto tmp = a;
        ranges::reverse(tmp);
        for (auto &x : tmp)
        {
            x += p;
            a.pb(x);
        }
        p *= 2;
    }
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}