#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    ranges::sort(a, [&](auto &a, auto &b)
                 { return a[2] > b[2]; });
    for (int i = 0; i < n; i++)
    {
        if (a[i][1] == 1)
            b.push_back(i);
    }
    int ans = 0;
    int posb = 0;
    int posa = 0;
    for (int i = 0; i < n; i++)
    {
        auto [cnt, w, val] = a[i];
        if (cnt == 0)
            continue;
        int c = cnt * w / k, r = cnt * w % k;
        ans += c * val;
        a[i][0] = 0;
        if (r == 0)
            continue;
        posa = max(posa, i + 1);
        while (posa < n)
        {
            if (k - r == 1)
                break;
            if (k - r >= a[posa][0] * a[posa][1])
            {
                r += a[posa][0] * a[posa][1];
                a[posa][0] = 0;
                posa++;
            }
            else
            {
                int c = (k - r) / a[posa][1];
                a[posa][0] -= c;
                r += c * a[posa][1];
                if (r == k)
                    break;
            }
        }
        if (k - r == 1)
        {
            while (posb < b.size() && a[b[posb]][0] == 0)
                posb++;
            if (posb < b.size())
                a[b[posb]][0]--;
        }
        ans += val;
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