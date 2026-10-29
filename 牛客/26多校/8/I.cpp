#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    int res1 = 0;
    int tar = a[0] + m;
    res1 += a[1] > tar;
    for (int i = 2; i < 2 * n; i += 2)
    {
        array<int, 2> aa = {a[i], a[i ^ 1]};
        ranges::sort(aa, greater<int>());
    if (aa[1] > tar)
        {     
            res1 += 2;
        }
        else if (aa[0] > tar)
        {
            res1++;
        }
        else
        {
            int r = 2 * tar - aa[0] - aa[1];
            if (m > r)
                res1++;
        }
    }
    tar = a[0];
    int res2 = (a[1] + m) > tar;
    for (int i = 2; i < 2 * n; i += 2)
    {
        array<int, 2> aa = {a[i], a[i ^ 1]};
        ranges::sort(aa, greater<int>());
        if (aa[1] > tar)
        {
            res2 += 2;
        }
        else if (aa[0] > tar)
        {
            res2 += 1 + ((aa[1] + m) > tar);
        }
        else
        {
            int d = 2 * tar - aa[0] - aa[1];
            if (m > d)
                res2 += 2;
            else if (m > tar - aa[0])
                res2++;
        }
    }
    cout << res1 << ' ' << res2 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
