#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (b & 1 && !(a & 1))
    {
        cout << -1 << '\n';
        return;
    }
    else if (b & 1 && a & 1)
    {
        cout << a * b + 1 << '\n';
    }
    else if (!(b & 1) && a & 1)
    {
        int c = b / 2;
        b = 2;
        a = a * c;
        if ((a + b) % 2 == 0)
            cout << a + b << '\n';
        else
            cout << -1 << '\n';
    }
    else
    {
        int c = b / 2;
        b = 2;
        a = a * c;
        if ((a + b) % 2 == 0)
            cout << a + b << '\n';
        else
            cout << -1 << '\n';
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
}