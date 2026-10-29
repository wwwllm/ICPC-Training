#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU
{
    vector<int> f, siz;
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
        st.clear();
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;

        // 启发式合并：小树合入大树，保证树高 O(log n)
        if (siz[x] < siz[y])
            swap(x, y);

        st.push_back({x, y}); // 记录谁成为了谁的父亲
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)];
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
    vector g(n + 1, string(" "));
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        g[i] += s;
    }
    int s, t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == 'S')
                s = i * m + j, g[i][j] = '.';
            if (g[i][j] == 'E')
                t = i * m + j, g[i][j] = '.';
        }
    }
    vector M(n + 1, vector<int>(m + 1));
    vector pos(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0, id = 0;
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == 'R')
            {
                cnt = 1;
                M[i][j] = 2;
                id = i * m + j;
            }
            else if (g[i][j] != '.')
                cnt = 0, M[i][j] = 2, id = 0;
            else if (cnt)
            {
                M[i][j] += cnt;
                pos[i][j] = id;
            }
        }
        cnt = 0, id = 0;
        for (int j = m; j >= 1; j--)
        {
            if (g[i][j] == 'L')
                cnt = 1,
                M[i][j] = 2,
                id = i * m + j;
            else if (g[i][j] != '.')
                cnt = 0,
                M[i][j] = 2,
                id = 0;
            else if (cnt)
                M[i][j] += cnt, pos[i][j] = id;
        }
    }
    for (int j = 1; j <= m; j++)
    {
        int cnt = 0, id = 0;
        for (int i = 1; i <= n; i++)
        {
            if (g[i][j] == 'D')
                cnt = 1, M[i][j] = 2, id = i * m + j;
            else if (g[i][j] != '.')
                cnt = 0, M[i][j] = 2, id = 0;
            else if (cnt)
                M[i][j] += cnt,
                    pos[i][j] = id;
        }
        cnt = 0, id = 0;
        for (int i = n; i >= 1; i--)
        {
            if (g[i][j] == 'U')
            {
                cnt = 1, M[i][j] = 2, id = i * m + j;
            }
            else if (g[i][j] != '.')
            {
                cnt = 0;
                M[i][j] = 2;
                id = 0;
            }
            else if (cnt)
            {
                M[i][j] += cnt;
                pos[i][j] = id;
            }
        }
    }
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    DSU dsu((n + 1) * m + 1);
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            if (M[x][y])
                continue;
            for (auto [dx, dy] : walk)
            {
                int xx = dx + x, yy = dy + y;
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m)
                {
                    if (M[xx][yy] == 0)
                    {
                        dsu.merge(x * m + y, xx * m + yy);
                    }
                }
            }
        }
    }
    if (dsu.find(s) == dsu.find(t))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (g[i][j] == 'D' || g[i][j] == 'U' || g[i][j] == 'R' || g[i][j] == 'L')
                {
                    cout << i << ' ' << j << '\n';
                    return;
                }
            }
        }
    }
    vector idx((n * m + m) + 1, vector<array<int, 2>>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (M[i][j] == 1)
            {
                idx[pos[i][j]].push_back({i, j});
            }
        }
    }
    for (int i = 1; i <= n * m + m; i++)
    {
        if (idx[i].empty())
            continue;
        int time = dsu.time();
        for (auto [x, y] : idx[i])
        {
            for (auto [dx, dy] : walk)
            {
                int xx = x + dx, yy = y + dy;
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m)
                {
                    if (M[xx][yy] == 0 || (M[xx][yy] == 1 && pos[xx][yy] == i))
                    {
                        dsu.merge(x * m + y, xx * m + yy);
                    }
                }
            }
        }
        if (dsu.find(s) == dsu.find(t))
        {
            int x = i / m, y = i % m;
            if (y == 0)
            {
                x--, y = m;
            }
            cout << x << ' ' << y << '\n';
            return;
        }
        dsu.roll_back(time);
    }
    cout << "-1 -1\n";
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