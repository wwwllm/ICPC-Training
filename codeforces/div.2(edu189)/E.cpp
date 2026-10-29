#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 998244353;

void solve()
{
    int n, r;
    cin >> n >> r;
    vector p(n, array<int, 2>{0});
    for (auto &[x, y] : p)
    {
        cin >> x >> y;
    }

    int w = 2 * r;
    int h = ceil(sqrtl(3) * r);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    auto div_floor = [&](int a, int b)
    {
        int q = a / b;
        int rem = a % b;
        if (rem < 0)
            q--;
        return q;
    };

    while (1)
    {
        int x0 = rng() % w;
        int y0 = rng() % h;

        vector<array<int, 2>> ans;
        int cnt = 0;

        for (auto [x, y] : p)
        {
            bool ok = 0;
            int row0 = div_floor(y - y0, h);
            for (int row = row0 - 2; row <= row0 + 2 && !ok; row++)
            {
                int d = ((row % 2) + 2) % 2;
                int sx = x0 + d * r;
                int sy = y0 + row * h;

                int col0 = div_floor(x - sx, w);

                for (int col = col0 - 2; col <= col0 + 2; col++)
                {
                    int cx = sx + col * w;
                    int cy = sy;

                    int dx = x - cx;
                    int dy = y - cy;

                    if (dx * dx + dy * dy <= r * r)
                    {
                        ans.push_back({cx, cy});
                        cnt++;
                        ok = 1;
                        break;
                    }
                }
            }
        }

        if (cnt * 100 < 89 * n)
            continue;

        ranges::sort(ans);
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        cout << ans.size() << '\n';
        for (auto [x, y] : ans)
            cout << x << ' ' << y << '\n';

        return;
    }
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