#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    auto f = [&]()
    {
        int len = a / (b + 1), r = a % (b + 1);
        for (int i = 0; i <= b; i++)
        {
            for (int k = 0; k < len + (i < r); k++)
            {
                ans.pb(0);
            }
            if (i < b)
                ans.pb(1);
        }
    };
    if (a >= b)
    {
        f();
    }
    else
    {
        swap(a, b);
        f();
        for (auto &x : ans)
        {
            x = !x;
        }
    }
    for (auto x : ans)
        cout << x;
    cout << '\n';
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