#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(m);
    int x = inf;
    for (auto &[l, r] : a)
    {
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        x = min(r, x);
    }
    vector<int> miv(n + 1, inf), mxu(n + 1), mxv(n + 1);
    for (auto [l, r] : a)
    {
        miv[l] = min(miv[l], r);
        mxv[l] = max(mxv[l], r);
        mxu[l] = max(mxu[l], l);
    }
    for (int i = 1; i <= n; i++)
    {
        mxv[i] = max(mxv[i], mxv[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        miv[i] = min(miv[i], miv[i + 1]);
        mxu[i] = max(mxu[i], mxu[i + 1]);
    }
    for (int a1 = 2; a1 <= x; a1++)
    {
        int l = max({a1 + 1,
                     mxv[a1 - 1] + 1,
                     mxu[a1] + 1});
        int r = min(miv[a1], n);
        if (l <= r)
        {
            cout << "Yes\n";
            cout << a1 << ' ' << l << '\n';
            return;
        }
    }

    cout << "No\n";
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
