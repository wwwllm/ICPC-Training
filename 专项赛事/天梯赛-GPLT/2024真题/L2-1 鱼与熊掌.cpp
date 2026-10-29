#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
bool b[N];
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        memset(b, 0, sizeof(b));
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        for (auto it : g[x])
            b[it] = 1;
        for (auto it : g[y])
            if (b[it])
                cnt++;
        cout << cnt << endl;
    }
}