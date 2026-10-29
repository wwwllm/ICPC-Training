#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int a, b, c, d, v, t;
    cin >> a >> b >> c >> d >> v >> t;
    int T = lcm(a, c);
    vector<int> tim;
    for (int i = 0; i <= T; i += a)
    {
        tim.push_back(i);
    }
    for (int i = 0; i <= T; i += c)
    {
        tim.push_back(i);
    }
    ranges::sort(tim);
    tim.erase(unique(tim.begin(), tim.end()), tim.end());
    int n = tim.size();
    int pre = v;
    vector<int> cnt(n);
    cnt[0] = b + d - 1;
    for (int i = 1; i < n - 1; i++)
    {
        cnt[i] = cnt[i - 1];
        if (tim[i] - tim[i - 1] > pre)
        {
            if (tim[i] % a == 0)
            {
                pre = v;
                cnt[i] += b - 1;
            }
            if (tim[i] % c == 0)
            {
                pre = v;
                cnt[i] += d - 1;
            }
        }
        else
        {
            if (tim[i] % a == 0)
            {
                pre = v;
                cnt[i] += b;
            }
            if (tim[i] % c == 0)
            {
                pre = v;
                cnt[i] += d;
            }
        }
    }

    int k = t / T, r = t % T;
    int pos = ranges::upper_bound(tim, r) - tim.begin() - 1;
    int ans = k * cnt[n - 2] + cnt[pos];
    if (tim[n - 1] - tim[n - 2] <= v)
    {
        ans += k;
    }
    cout << ans << '\n';
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