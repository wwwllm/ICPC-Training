#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Info
{
    int siz, l, r;
    array<int, 4> tim;
};
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    vector<Info> info(n);
    vector<int> vis(n);
    vector<int> nxt(n), pre(n);
    for (int i = 0; i < n; i++)
    {
        info[i] = {1, p[i], p[i], {0, 0, 0, 0}};
        pre[i] = i - 1;
        nxt[i] = i + 1 < n ? i + 1 : -1;
    }
    auto check = [&](int x, int y) -> bool
    {
        if (vis[x] || vis[y])
        {
            return 0;
        }
        if (nxt[x] != y)
            return 0;
        return info[x].r + 1 == info[y].l || info[y].r + 1 == info[x].l;
    };
    auto merge = [&](int x, int y)
    {
        auto A = info[x];
        auto B = info[y];

        int a = A.siz;
        int b = B.siz;
        int s = a + b;
        Info C;
        C.siz = s;
        C.l = min(A.l, B.l);
        C.r = max(A.r, B.r);
        if (A.r + 1 == B.l)
        {
            int t = max(A.tim[3], B.tim[0]) + s - 1;
            C.tim[0] = A.tim[0];
            C.tim[3] = B.tim[3];
            C.tim[1] = max({A.tim[1] + b, B.tim[1] + a, t});
            C.tim[2] = max({A.tim[2] + b, B.tim[2] + a, t});
        }
        else
        {
            int t = max(A.tim[2], B.tim[1]) + s - 1;
            C.tim[1] = A.tim[1];
            C.tim[2] = B.tim[2];
            C.tim[0] = max({A.tim[0] + b, B.tim[0] + a, t});
            C.tim[3] = max({A.tim[3] + b, B.tim[3] + a, t});
        }
        info[x] = C;
        vis[y] = 1;
        nxt[x] = nxt[y];
        if (nxt[y] != -1)
            pre[nxt[y]] = x;
    };
    queue<array<int, 2>> q;
    for (int i = 0; i < n - 1; i++)
    {
        if (check(i, i + 1))
        {
            q.push({i, i + 1});
        }
    }
    int cnt = n;
    while (q.size() && cnt != 1)
    {
        auto [x, y] = q.front();
        q.pop();
        if (!check(x, y))
            continue;
        int l = pre[x];
        merge(x, y);
        cnt--;
        if (check(l, x))
            q.push({l, x});
        if (check(x, nxt[x]))
            q.push({x, nxt[x]});
    }
    if (cnt != 1)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cout << *ranges::max_element(info[i].tim) << '\n';
        }
    }
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
