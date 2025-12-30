#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> row(n + 1), col(m + 1);
    map<int, set<int>> crow, ccol;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        row[x]++;
        col[y]++;
        ccol[y].insert(x);
        crow[x].insert(y);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            cout << row[x] << '\n';
            row[x] = 0;
            for (auto it : crow[x])
            {
                ccol[it].erase(x);
                col[it]--;
            }
            crow[x].clear();
        }
        else
        {
            cout << col[x] << '\n';
            col[x] = 0;
            for (auto it : ccol[x])
            {
                crow[it].erase(x);
                row[it]--;
            }
            ccol[x].clear();
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}