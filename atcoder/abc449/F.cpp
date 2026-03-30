#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Info
{
    int cnt, len;
    int size;
    Info() : cnt(0), len(0) {};
};
struct SegTree
{
    int n;
    vector<Info> info;
    vector<int> vy;
    SegTree(vector<int> vy) : n(vy.size()), info(4 * vy.size()), vy(vy) {};
    void pull(int p, int l, int r)
    {
        if (info[p].cnt)
            info[p].len = vy[r] - vy[l];
        else
        {
            if (r - l == 1)
                info[p].len = 0;
            else
                info[p].len = info[p << 1 | 1].len + info[p << 1].len;
        }
    }
    void modify(int p, int l, int r, int x, int y, int v)
    {
        if (vy[l] >= y || vy[r] <= x)
            return;
        if (vy[l] >= x && vy[r] <= y)
        {
            info[p].cnt += v;
            pull(p, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        modify(p << 1, l, mid, x, y, v);
        modify(p << 1 | 1, mid, r, x, y, v);
        pull(p, l, r);
    }
    void modify(int x, int y, int v)
    {
        modify(1, 0, n - 1, x, y, v);
    }
    int get_len()
    {
        return info[1].len;
    }
};
void solve()
{
    int H, W, h, w, n;
    cin >> H >> W >> h >> w >> n;
    vector<array<int, 2>> point(n);
    vector<int> vy;
    for (auto &[x, y] : point)
        cin >> x >> y;
    vy.push_back(1);
    vy.push_back(W + 1);
    vector<array<int, 4>> seg;
    for (auto [x, y] : point)
    {
        int x_low = max(1LL, x - h + 1),
            x_up = min(H - h + 1, x) + 1;
        int yl = max(y - w + 1, 1LL),
            yr = min(W - w + 1, y) + 1;
        seg.push_back({x_low, yl, yr, 1});
        seg.push_back({x_up, yl, yr, -1});
        // cerr << x_low << ' ' << x_up << ' ' << yl << ' ' << yr << '\n';
        vy.push_back(yl);
        vy.push_back(yr);
    }
    ranges::sort(vy);
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    ranges::sort(seg, [&](const array<int, 4> &a, const array<int, 4> &b)
                 { return a[0] < b[0]; });
    SegTree T(vy);
    int cnt = 0;
    for (int i = 0; i < (int)seg.size() - 1; i++)
    {
        auto [x, yl, yr, v] = seg[i];
        int nxtx = seg[i + 1][0];
        T.modify(yl, yr, v);
        cnt += T.get_len() * (nxtx - x);
        // cerr << cnt << '\n';
    }
    cout << (H - h + 1) * (W - w + 1) - cnt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}