#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        deg[i] = ranges::count(g[i], '1');
    }
    vector<int> ord(n);
    ranges::iota(ord, 0);
    ranges::sort(ord, [&](int a, int b)
                 { return deg[a] > deg[b]; });
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int u = ord[i];
        if (deg[u] == deg[ord[0]])
            ans.push_back(u + 1), cerr << u + 1 << " ";
        else
        {
            bool flag = 1;
            for (auto v : ans)
            {
                v--;
                bool ok = 0;
                for (int j = 0; j < n; j++)
                {
                    if (g[u][j] == '1' && g[v][j] == '0')
                        ok = 1;
                }
                flag &= ok;
            }
            if (flag)
                ans.push_back(u + 1);
        }
        if (ans.size() == 3)
            break;
    }
    if (ans.size() == 3)
    {
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
    else
    {
        cout << "NOT FOUND\n";
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
