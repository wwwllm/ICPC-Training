#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 4e18;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int p = 1;
    while (p <= b)
    {
        p <<= 1;
    }
    vector dist(p, vector<int>(b, inf));
    dist[a % p][a % b] = a;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({a, a % p, a % b});
    while (pq.size())
    {
        auto [d, u, v] = pq.top();
        pq.pop();
        if (dist[u][v] != d)
            continue;
        {
            int nu = (u + b) % p;
            int nv = v;
            int w = b;
            if (dist[nu][nv] > d + w)
            {
                dist[nu][nv] = d + w;
                pq.push({d + w, nu, nv});
            }
        }
        {
            int nu = (u ^ b) % p;
            int w = nu - u;
            int nv = (v + w + b) % b;
            if (dist[nu][nv] > d + w)
            {
                dist[nu][nv] = d + w;
                pq.push({d + w, nu, nv});
            }
        }
    }
    if (dist[c % p][c % b] <= c)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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