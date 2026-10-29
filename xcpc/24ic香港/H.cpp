#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 8;
vector<int> p3(N + 1);
void init()
{
    p3[0] = 1;
    for (int i = 1; i <= N; i++)
        p3[i] = p3[i - 1] * 3;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]--;
    vector<array<int, 8>> d(p3[6], {0});
    for (int mask = 0; mask < p3[6]; mask++)
    {
        for (int bit = 0; bit < 6; bit++)
        {
            int c = mask / p3[bit] % 3;
            for (int i = 0; i < 3; i++)
            {
                d[mask][i + bit] += c;
            }
        }
    }
    vector<int> val(p3[6]);
    for (int mask = 0; mask < p3[6]; mask++)
    {
        for (int i = 0; i < 8; i++)
        {
            int x = d[mask][i] % 3;
            val[mask] += x * p3[i];
        }
    }
    vector pre(n + 1, array<int, 8>{});
    vector<int> st(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        pre[i][a[i]]++;
        int mask = 0;
        for (int bit = 0; bit < 8; bit++)
        {
            int x = pre[i][bit] % 3;
            mask += x * p3[bit];
        }
        st[i] = mask;
    }
    vector<int> cnt(p3[N]);
    auto add = [&](int &pos)
    {
        cnt[st[pos]]++;
        pos++;
    };
    auto check = [&](int mask, int l, int r) -> bool
    {
        for (int i = 0; i < 8; i++)
        {
            if (d[mask][i] > pre[r][i] - pre[l][i])
                return 0;
        }
        return 1;
    };
    int ans = 0;
    for (int mask = 0; mask < p3[6]; mask++)
    {
        cnt.assign(p3[N], 0);
        for (int i = 1, j = 0; i <= n; i++)
        {
            while (j < i && check(mask, j, i))
                add(j);
            int tar = 0;
            for (int bit = 0; bit < 8; bit++)
            {
                int c = (pre[i][bit] - d[mask][bit]) % 3;
                (c += 3) %= 3;
                tar += c * p3[bit];
            }
            ans += cnt[tar];
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}