#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int EPS = 1e-9;
inline int sgn(double x)
{
    return x < -EPS ? -1 : (x > EPS ? 1 : 0);
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int res = 0;
    for (auto [x, c] : mp)
    {
        int cnt = cur + c;
        double p = (double)cnt / (double)n;
        if (sgn(p - 0.8) == 1)
        {
            res += c * x;
        }
        cur += c;
    }
    cout << res << '\n';
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