#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    auto check = [&]() -> bool
    {
        bool ok = 0;
        if (l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1)
            ok = 1;
        else if (l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1)
            ok = 1;
        return ok;
    };
    bool ok = 0;
    ok |= check();
    swap(l1, b1), swap(l2, b2), swap(l3, b3);
    ok |= check();
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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