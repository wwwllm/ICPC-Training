#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9, N = 2e3 + 10;
vector<array<int, 4>> a;
int n, q;
int x, y;
bool cmp(const array<int, 4> &a, const array<int, 4> &b)
{
    auto [x1, y1, t1, p1] = a;
    auto [x2, y2, t2, p2] = b;
    int d1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
    int d2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);
    if (d1 != d2)
        return d1 < d2;
    else
        return p1 < p2;
}
signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int xx, yy, t;
        cin >> xx >> yy >> t;
        a.push_back({xx, yy, t, i});
    }
    cin >> x >> y;
    sort(a.begin(), a.end(), cmp);
    while (q--)
    {
        int k;
        cin >> k;
        map<int, int> mp;
        int ans = 0, ti = 0;
        for (int i = 0; i < k; i++)
        {
            auto [xx, yx, t, pos] = a[i];
            mp[t]++;
            if (mp[t] == ti && t < ans)
                ans = t;
            if (mp[t] > ti)
            {
                ans = t, ti = mp[t];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
