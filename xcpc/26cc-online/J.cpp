#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(2 * n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        a[i + n] = a[i];
    }
    vector<int> pre(2 * n);
    pre[0] = a[0];
    for (int i = 1; i < 2 * n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    auto query = [&](int l, int r) -> int
    {
        if (l == 0)
            return pre[r];
        else
            return pre[r] - pre[l - 1];
    };
    vector adj(2 * n + 1, vector<int>{});
    vector<int> nxt(2 * n, n + 1);
    auto check = [&](int x) -> bool
    {
        adj.assign(n * 2 + 1, {});
        nxt.assign(2 * n, n + 1);
        for (int i = 0, j = 0; i < 2 * n; i++)
        {
            if (a[i] > x)
                return 0;
            while (j < 2 * n && query(i, j) <= x)
                j++;
            nxt[i] = j;
        }
        vector<int> path;
        for (int i = 0; i < 2 * n; i++)
        {
            adj[nxt[i]].push_back(i);
        }
        auto dfs = [&](auto &&self, int u) -> bool
        {
            if (u < n)
            {
                if (path.size() <= k)
                    return 1;
                else if (path[path.size() - 1 - k] >= u + n)
                    return 1;
            }
            for (auto v : adj[u])
            {
                path.push_back(v);
                if (self(self, v))
                    return 1;
                path.pop_back();
            }
            return 0;
        };
        return dfs(dfs, 2 * n);
    };
    int l = *ranges::max_element(a) - 1, r = sum + 1;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << sum + (m - 1) * r << '\n';
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
// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> a(2 * n);
//     long long sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         sum += a[i];
//         a[i + n] = a[i];
//     }
//     vector<long long> pre(2 * n);
//     pre[0] = a[0];
//     for (int i = 1; i < 2 * n; i++)
//     {
//         pre[i] = pre[i - 1] + a[i];
//     }
//     auto query = [&](int l, int r) -> long long
//     {
//         if (l == 0)
//             return pre[r];
//         else
//             return pre[r] - pre[l - 1];
//     };
//     vector<array<int, 21>> f(2 * n + 1, {0});
//     for (int i = 0; i < 20; i++)
//     {
//         f[2 * n][i] = 2 * n;
//     }
//     vector<int> nxt(2 * n, n + 1);
//     auto check = [&](long long x) -> bool
//     {
//         nxt.assign(2 * n, n + 1);
//         for (int i = 0, j = 0; i < 2 * n; i++)
//         {
//             if (a[i] > x)
//                 return 0;
//             while (j < 2 * n && query(i, j) <= x)
//                 j++;
//             nxt[i] = j;
//         }
//         for (int i = 2 * n - 1; i >= 0; i--)
//         {
//             f[i][0] = nxt[i];
//             for (int j = 1; j <= 20; j++)
//             {
//                 f[i][j] = f[f[i][j - 1]][j - 1];
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             int u = i;
//             for (int j = 20; j >= 0; j--)
//             {
//                 if (k >> j & 1)
//                 {
//                     u = f[u][j];
//                 }
//             }
//             if (u >= i + n)
//                 return 1;
//         }
//         return 0;
//     };
//     long long l = *ranges::max_element(a) - 1, r = sum + 1;
//     while (l + 1 != r)
//     {
//         long long mid = l + r >> 1;
//         if (check(mid))
//             r = mid;
//         else
//             l = mid;
//     }
//     cout << sum + (long long)(m - 1) * r << '\n';
// }

// signed main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//     int t = 1;
//     // cin >> t;

//     while (t--)
//         solve();

//     return 0;
// }