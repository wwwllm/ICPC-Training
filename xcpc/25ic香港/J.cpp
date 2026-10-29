#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;

    vector<int> l(3);
    for (int i = 0; i < 3; i++)
        cin >> l[i];
    vector<vector<int>> g(3);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int p, c;
        cin >> p >> c;
        p--;
        g[p].push_back(c);
        cur += c;
    }
    int t;
    cin >> t;
    vector<int> ord = {0, 1, 2};
    ranges::sort(ord, [&](int x, int y)
                 { return l[x] > l[y]; });
    priority_queue<int> q;
    int j = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < 3 && l[ord[j]] >= cur)
        {
            int p = ord[j];
            for (auto c : g[p])
                q.push(c);
            j++;
        }
        if (q.empty())
        {
            cout << "NO\n";
            return;
        }
        int c = q.top();
        q.pop();
        res += cur;
        cur -= c;
    }

    cout << (res < t ? "YES\n" : "NO\n");
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}