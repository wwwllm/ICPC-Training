#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105423
const int mod = 998244353;
const double eps = 1e-9;
int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    double sum = 1;
    for (int i = 1; i <= n; i++)
    {
        double x;
        cin >> x;
        sum *= x;
        while (sign(sum - 1.0) == 1)
            sum /= 2024.0, ans++;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}