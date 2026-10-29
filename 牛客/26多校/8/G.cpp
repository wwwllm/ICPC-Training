#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    string x1(a, '9');
    x1 += string(b, '0');
    string y1 = "1";
    y1 += string(2 * b - 1, '0');
    string x2(a + b, '9');
    string y2 = "1";
    y2 += string(b - 1, '0');
    y2 += string(b, '9');

    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
