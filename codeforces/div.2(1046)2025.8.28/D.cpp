#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i][0] >> p[i][1];
    }
    int tmp;
    cout << "? U " << inf << endl;
    cin >> tmp;
    cout << "? U " << inf << endl;
    cin >> tmp;
    cout << "? R " << inf << endl;
    cin >> tmp;
    cout << "? R " << inf << endl;
    cin >> tmp;
    int a = tmp;
    array<int, 2> x = {-inf, -inf};
    for (auto [i, j] : p)
    {
        if (i + j > x[0] + x[1])
            x = {i, j};
    }
    cout << "? L " << inf << endl;
    cin >> tmp;
    cout << "? L " << inf << endl;
    cin >> tmp;
    cout << "? L " << inf << endl;
    cin >> tmp;
    cout << "? L " << inf << endl;
    cin >> tmp;
    cout << "? L " << inf << endl;
    cin >> tmp;
    cout << "? L " << inf << endl;
    cin >> tmp;
    int b = tmp;
    array<int, 2> y = {inf, -inf};
    for (auto [i, j] : p)
    {
        if (j - i > y[1] - y[0])
            y = {i, j};
    }
    int k = b + x[0] - y[0] + y[1] - x[1];
    int dy = (k + a - 6 * inf) / 2;
    int X = x[0], Y = x[1];
    Y += dy;
    X += a - dy;
    X -= 2 * inf;
    Y -= 2 * inf;
    cout << "! " << X << ' ' << Y << endl;
    cout.flush();
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