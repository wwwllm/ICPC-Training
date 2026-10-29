#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    vector<array<int, 2>> p = {{0, 0}, {a, 0}, {0, b}, {a, b}};
    ranges::sort(p);
    p.erase(unique(p.begin(), p.end()), p.end());
    unordered_set<int> X, Y;
    X.insert(0), X.insert(a);
    Y.insert(0), Y.insert(b);
    int l = 0, r = a;
    bool ok1 = x == a || x == 0, ok2 = y == 0 || y == b;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= 100 && !ok1; i++)
    {
        if ((l + r) % 2 == 0)
        {
            int mid = l + r >> 1;
            cnt1++;
            X.insert(mid);
            if (x < mid)
                r = mid;
            else if (x > mid)
                l = mid;
            else
            {
                ok1 = 1;
                break;
            }
        }
        else
            break;
    }
    l = 0, r = b;
    for (int i = 1; i <= 100 && !ok2; i++)
    {
        if ((l + r) % 2 == 0)
        {
            int mid = l + r >> 1;
            cnt2++;
            Y.insert(mid);
            if (y < mid)
                r = mid;
            else if (y > mid)
                l = mid;
            else
            {
                ok2 = 1;
                break;
            }
        }
        else
            break;
    }
    if (!ok1 || !ok2)
    {
        cout << -1 << '\n';
        return;
    }
    vector<array<int, 4>> ans;
    int curx = x, cury = y;
    for (int i = 0; i < max(cnt1, cnt2); i++)
    {
        int cx = 2 * curx >= a ? a : 0;
        int cy = 2 * cury >= b ? b : 0;
        int px = 2 * curx - cx;
        int py = 2 * cury - cy;
        ans.push_back({px, py, cx, cy});
        curx = px;
        cury = py;
    }
    ranges::reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto a : ans)
    {
        for (auto x : a)
        {
            cout << x << ' ';
        }
        cout << '\n';
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