#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU
{
    vector<int> f, siz;
    vector<int> dis;
    int cnt;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        dis.assign(n, 0);
        cnt = n;
    }

    int find(int x)
    {
        if (x == f[x])
            return f[x];
        int fa = f[x];
        f[x] = find(f[x]);
        dis[x] ^= dis[fa];
        return f[x];
    }

    bool merge(int x, int y, int w)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)
            return (dis[x] ^ dis[y]) == w;
        siz[fx] += siz[fy];
        cnt--;
        f[fy] = fx;
        dis[fy] = dis[x] ^ dis[y] ^ w;
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
};
const int N = 150 * 150 * 3;
void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    vector g(x, vector<string>(y));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> g[i][j];
        }
    }
    auto idX = [&](int i, int j)
    {
        return i * y + j;
    };

    auto idY = [&](int j, int k)
    {
        return x * y + j * z + k;
    };

    auto idZ = [&](int k, int i)
    {
        return x * y + y * z + k * x + i;
    };

    DSU dsu(N);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                int X = idX(i, j), Y = idY(j, k), Z = idZ(k, i);
                if (g[i][j][k] == 'R')
                {
                    dsu.merge(X, Z, 0);
                    dsu.merge(X, Y, 1);
                }
                else if (g[i][j][k] == 'G')
                {
                    dsu.merge(X, Y, 0);
                    dsu.merge(X, Z, 1);
                }
                else
                {
                    dsu.merge(Y, Z, 0);
                    dsu.merge(X, Y, 1);
                }
            }
        }
    }
    vector<int> val(N);
    for (int i = 0; i < N; i++)
    {
        dsu.find(i);
        val[i] = dsu.dis[i];
    }
    vector adj(x + y + z, vector<int>());
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            int R = i;
            int G = x + j;

            if (val[idX(i, j)])
                adj[R].push_back(G);
            else
                adj[G].push_back(R);
        }
    }

    for (int j = 0; j < y; j++)
    {
        for (int k = 0; k < z; k++)
        {
            int G = x + j;
            int B = x + y + k;

            if (val[idY(j, k)])
                adj[G].push_back(B);
            else
                adj[B].push_back(G);
        }
    }

    for (int k = 0; k < z; k++)
    {
        for (int i = 0; i < x; i++)
        {
            int B = x + y + k;
            int R = i;

            if (val[idZ(k, i)])
                adj[B].push_back(R);
            else
                adj[R].push_back(B);
        }
    }
    queue<int> q;
    vector<int> ind(x + y + z);
    for (int i = 0; i < x + y + z; i++)
    {
        for (auto u : adj[i])
        {
            ind[u]++;
        }
    }
    for (int i = 0; i < x + y + z; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    vector<int> ansr(x), ansg(y), ansb(z);
    auto Push = [&](int i, int rank)
    {
        if (i < x)
            ansr[i] = rank;
        else if (i < x + y)
            ansg[i - x] = rank;
        else
            ansb[i - (x + y)] = rank;
    };
    int cur = 1;
    while (q.size())
    {
        auto u = q.front();
        Push(u, cur++);
        q.pop();
        for (auto v : adj[u])
        {
            if (ind[v] == 0)
                continue;
            ind[v]--;
            if (ind[v] == 0)
                q.push(v);
        }
    }
    for (int i = 0; i < x; i++)
    {
        cout << ansr[i] << " \n"[i == x - 1];
    }
    for (int i = 0; i < y; i++)
    {
        cout << ansg[i] << " \n"[i == y - 1];
    }
    for (int i = 0; i < z; i++)
    {
        cout << ansb[i] << " \n"[i == z - 1];
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