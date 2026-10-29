#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
const int n = 16;
array<int, 4> a{0};
vector<int> val(15, inf);
int N = 1LL << n;
vector<int> dist(N, inf);
vector adj(N, vector<array<int, 2>>());
void init()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    for (int bit = 0; bit < 4; bit++)
        val[1LL << bit] = a[0];
    val[3] = a[1];
    val[3 << 2] = a[1];
    val[5] = a[2];
    val[10] = a[2];
    val[15] = a[3];
    for (int mask = 0; mask < N; mask++)
    {
        for (int op = 0; op < n; op++)
        {
            if (val[op] == inf)
                continue;
            int nmsk = 0;
            for (int bit = 0; bit < 16; bit++)
            {
                if ((mask >> bit) & 1)
                {
                    int nbit = bit ^ op;
                    if (nbit == 15)
                        continue;
                    nmsk |= (1LL << nbit);
                }
            }
            adj[nmsk].push_back({mask, val[op]});
        }
    }
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] != d)
            continue;
        for (auto [v, cost] : adj[u])
        {
            if (d + cost < dist[v])
            {
                pq.push({d + cost, v});
                dist[v] = d + cost;
            }
        }
    }
}
void solve()
{
    int m;
    cin >> m;
    int st = 0;
    for (int i = 0; i < m; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        auto ss = s1 + s2;
        int bit = 0;
        for (int i = 0; i < 4; i++)
        {
            bit = bit * 2 + ss[i] - '0';
        }
        st |= (1LL << bit);
    }
    cout << dist[st] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}