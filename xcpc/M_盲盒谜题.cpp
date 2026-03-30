#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105481
vector<array<int, 2>> num = {{1, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
vector<array<int, 3>> a = {{0, 1, 8}, {0, 2, 7}, {0, 3, 6}, {0, 4, 5}, {1, 2, 3}, {1, 4, 6}, {3, 5, 8}, {6, 7, 8}};
void solve()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    queue<int> q;
    vector<int> ans(m + 1);
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int cnt = n;
    vector g(3, vector<int>(3, -1));
    auto init = [&]() -> array<bool, 2>
    {
        bool f = 0;
        for (auto [x, y] : num)
        {
            if (g[x][y] == -1 && cnt > 0 && q.size())
            {
                g[x][y] = q.front();
                q.pop();
                cnt--;
                f = 1;
                if (g[x][y] == t)
                {
                    cnt++;
                }
                if (g[x][y] == 0)
                {
                    ans[0]++;
                    cnt++;
                    g[x][y] = -1;
                    return {1, 1};
                }
            }
        }
        return {0, f};
    };
    auto check2 = [&]() -> bool
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = i + 1; j < 9; j++)
            {
                auto [x1, y1] = num[i];
                auto [x2, y2] = num[j];
                if (g[x1][y1] == g[x2][y2] || g[x1][y1] == -1)
                    return 1;
            }
        }
        return 0;
    };
    auto f1 = [&]() -> array<bool, 2>
    {
        bool f1 = 0, f2 = 0;
        for (auto l : a)
        {
            bool ok = 1;
            int col = -1;
            for (auto p : l)
            {
                auto [x, y] = num[p];
                if (g[x][y] == -1)
                    ok = 0;
                else if (col == -1 || g[x][y] == col)
                    col = g[x][y];
                else
                    ok = 0;
            }
            if (ok)
            {
                f2 = 1;
                cnt += 5;
                for (auto p : l)
                {
                    int x = num[p][0], y = num[p][1];
                    if (x == 1 && y == 1)
                    {
                        f1 = 1;
                    }
                    else
                    {
                        ans[g[x][y]]++;
                        g[x][y] = -1;
                    }
                }
            }
        }
        return {f1, f2};
    };
    auto f2 = [&]() -> array<bool, 2>
    {
        bool f1 = 0, f2 = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = i + 1; j < 9; j++)
            {
                auto [x1, y1] = num[i];
                auto [x2, y2] = num[j];
                if (g[x1][y1] == g[x2][y2] && g[x1][y1] != -1)
                {
                    cnt += 1;
                    f2 = 1;
                    for (auto p : {i, j})
                    {
                        auto [x, y] = num[p];
                        if (x == 1 && y == 1)
                            f1 = 1;
                        else
                        {
                            ans[g[x][y]]++;
                            g[x][y] = -1;
                        }
                    }
                }
            }
        }
        return {f1, f2};
    };
    while (1)
    {
        bool ok1 = 0, ok2 = 0;
        auto tmp = init();
        if (tmp[0])
            continue;
        if (!check2())
        {
            ans[g[1][1]]++;
            g[1][1] = -1;
            continue;
        }
        ok2 |= tmp[1];
        tmp = f1();
        ok1 |= tmp[0];
        ok2 |= tmp[1];
        tmp = f2();
        ok1 |= tmp[0];
        ok2 |= tmp[1];
        if (ok1)
        {
            ans[g[1][1]]++;
            g[1][1] = -1;
        }
        bool f = 0;
        for (int i = 0; i < 9; i++)
        {
            auto [x, y] = num[i];
            if (g[x][y] != -1)
                f = 1;
        }
        if (!ok2)
        {
            for (int i = 0; i < 9; i++)
            {
                auto [x, y] = num[i];
                if (g[x][y] != -1)
                {
                    ans[g[x][y]]++;
                    g[x][y] = -1;
                }
            }
            break;
        }
        else
        {
            if (!f)
                cnt += 10;
        }
    }
    int dept = cnt - q.size();
    if (dept > 0)
    {
        for (int i = 0; i <= m; i++)
            cout << ans[i] << " \n"[i == m];
        cout << "Unhappy! " << dept << '\n';
    }
    else
    {
        for (int i = 0; i <= m; i++)
            cout << ans[i] << " \n"[i == m];
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