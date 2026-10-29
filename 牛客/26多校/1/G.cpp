#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 1e-9;
void solve()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(9);
    if (n == 1)
    {
        cout << 2 << '\n';
        cout << (double)0 << ' ' << (double)0 << ' ' << (double)0 << '\n';
        cout << (double)0 << ' ' << (double)0<< ' ' << (double)1 << '\n';
        return;
    }
    vector<array<double, 2>> p(n);
    int h = sqrt(n);
    double d = 0.01 + eps;
    for (int i = 0; i < n; i++)
    {
        int r = i / h, c = i % h;
        p[i] = {r * d, c * d};
    }
    cout << n * 2 << '\n';
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = p[i];
        cout << x << ' ' << y << ' ' << (double)0 << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = p[i];
        cout << x << ' ' << y << ' ' << (double)1 << '\n';
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