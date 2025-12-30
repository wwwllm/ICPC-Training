#include <bits/stdc++.h>
using namespace std;
// using ll = long long;

void solve()
{
    int p, s;
    cin >> p >> s;
    int g = gcd(p, s);
    p /= g, s /= g;
    if (p & 1)
        p *= 2, s *= 2;
    if (p > s * 2 + 2)
    {
        cout << -1 << '\n';
        return;
    }
    if (p == 2 * s + 2)
    {
        cout << s << '\n';
        for (int i = 0; i < s; i++)
            cout << "0 " << i << '\n';
        return;
    }
    int k = 40000 / s;
    s *= k;
    p *= k;
    cout << s << '\n';
    int a = p / 4;
    int b = p / 2 - a;
    for (int i = 0; i < a; i++)
        cout << i << " 0" << '\n';
    for (int i = 1; i < b; i++)
        cout << "0 " << i << '\n';
    s -= a + b - 1;
    for (int i = 1; i < a; i++)
        for (int j = 1; j < b; j++)
        {
            if (s)
            {
                cout << i << ' ' << j << '\n';
                s--;
            }
            else
                break;
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