#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9;
struct DSU
{
    vector<int> f, siz;
    vector<int> dis;
    int cnt;
    vector<pair<int, int>> st; // 记录历史操作的栈

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
        dis.assign(n, 0);
        st.clear();
    }

    array<int, 2> find(int x)
    {
        if (x == f[x])
            return {x, dis[x]};
        auto [fa, d] = find(f[x]);
        return {fa, d + dis[x]};
    }

    bool merge(int x, int y, int w)
    {
        auto [fx, dx] = find(x);
        auto [fy, dy] = find(y);
        if (fx == fy)
        {
            return dx - dy == w;
        }

        // 启发式合并：小树合入大树，保证树高 O(log n)
        if (siz[fx] < siz[fy])
        {
            swap(fx, fy);
            swap(dx, dy);
            w *= -1;
        }

        st.push_back({fx, fy}); // 记录谁成为了谁的父亲
        siz[fx] += siz[fy];
        dis[fy] = dx - dy - w;
        cnt--;
        f[fy] = fx;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)[0]];
    }

    int count()
    {
        return cnt;
    }

    // 获取当前时间戳
    int time()
    {
        return st.size();
    }

    // 回滚至指定时间戳 t
    void roll_back(int t)
    {
        while (st.size() > t)
        {
            auto [x, y] = st.back();
            st.pop_back();
            dis[y] = 0;
            f[y] = y;         // 恢复父节点指向自己
            siz[x] -= siz[y]; // 恢复连通块大小
            cnt++;            // 恢复连通块数量
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    int k = 0;
    auto calc = [&](int &i, int &j, int &c)
    {
        i = (i + k - 1) % n + 1;
        j = (j + k - 1) % n + 1;
        c = (c + k) % mod + 1;
    };
    DSU dsu(2 * n + 2);

    while (m--)
    {
        int i, j, c;
        cin >> i >> j >> c;
        calc(i, j, c);
        if (i == j)
        {
            int u = 2 * i;
            if (dsu.merge(u, u ^ 1, 2 * c))
            {
                k++;
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            int time = dsu.time();
            int u = 2 * i, v = 2 * j;
            if (dsu.merge(u, v ^ 1, 2 * c) && dsu.merge(v, u ^ 1, 2 * c))
            {
                k++;
                cout << "Yes\n";
            }
            else
            {
                dsu.roll_back(time);
                cout << "No\n";
            }
        }
    }
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
