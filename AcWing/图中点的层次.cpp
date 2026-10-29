#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, m;
queue<int> q;
vector<int> g[maxn];
int d[maxn];
signed main()
{
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
    }
    q.push(1);
    d[1] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto son : g[t])
        {
            if (d[son] == -1)
            {
                d[son] = d[t] + 1;
                q.push(son);
            }
        }
    }
    cout << d[n] << endl;
    return 0;
}