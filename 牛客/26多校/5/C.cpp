#include <bits/stdc++.h>
#define int long long
using namespace std;

struct euler
{
    vector<vector<array<int, 2>>> adj;
    vector<int> ind, out;
    vector<int> cur;
    int n, m;
    euler(int n) : n(n), m(0), adj(n), ind(n), out(n) {}
    void add(int u, int v, int id)
    {
        adj[u].push_back({v, id});
        out[u]++, ind[v]++;
        m++;
    };

    vector<int> work()
    {
        vector<int> res;
        int s = -1, t = -1;
        for (int i = 0; i < n; i++)
        {
            if (out[i] == ind[i] + 1)
            {
                if (s != -1)
                    return res;
                s = i;
            }
            else if (ind[i] == out[i] + 1)
            {
                if (t != -1)
                    return res;
                t = i;
            }
            else if (out[i] != ind[i])
                return res;
        }
        if (s == -1)
        {
            for (int i = 0; i < n; i++)
            {
                if (out[i] != 0)
                {
                    s = i;
                    break;
                }
            }
        }
        if (s == -1)
            return res;
        cur.assign(n, 0);
        auto dfs = [&](auto &&self, int u) -> void
        {
            for (int &i = cur[u]; i < adj[u].size();)
            {
                auto [v, id] = adj[u][i++];
                self(self, v);
                res.push_back(id);
            }
        };
        dfs(dfs, s);
        ranges::reverse(res);
        if (res.size() != m)
            res.clear();
        return res;
    }
};

void solve()
{
    int B;
    cin >> B;
    if (B == 4)
    {
        cout << "0 1 2 3\n";
        cout << "1 3 0 2\n";
        cout << "2 0 3 1\n";
        return;
    }
    if (B & 1 || B == 2)
    {
        cout << -1 << '\n';
        return;
    }

    int n = B / 2;
    vector<int> a(B), d(B);
    vector<int> p(B), q(B), r(B);

    for (int i = 0; i < B; i++)
    {
        a[i] = (i < n);
    }
    swap(a[1], a[n + 1]);

    euler e(2);

    for (int i = 0; i < B; i++)
    {
        p[i] = i;
        q[i] = (i - 2 + B) % B;

        int s = p[i] + q[i] + a[i];

        r[i] = s % B;
        d[i] = s / B;

        e.add(a[i], d[i], i);
    }

    vector<int> order = e.work();

    if (order.size() != B)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> P(B), Q(B), R(B);
    for (int i = 0; i < B; i++)
    {
        int id = order[i];
        P[i] = p[id];
        Q[i] = q[id];
        R[i] = r[id];
    }
    ranges::reverse(P);
    ranges::reverse(Q);
    ranges::reverse(R);

    for (int i = 0; i < B; i++)
    {
        cout << P[i] << " \n"[i == B - 1];
    }
    for (int i = 0; i < B; i++)
    {
        cout << Q[i] << " \n"[i == B - 1];
    }
    for (int i = 0; i < B; i++)
    {
        cout << R[i] << " \n"[i == B - 1];
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