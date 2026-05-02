#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), d(n), pos(n + 1);
    for (int i = 0; i < n; i++)
        cin >> p[i], pos[p[i]] = i;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    vector<int> q;
    for (int i = n; i >= 1; i--)
    {
        int cnt = 0;
        for (auto idx : q)
        {
            if (idx > pos[i])
                cnt++;
        }
        if (d[pos[i]] > cnt)
        {
            cout << -1 << '\n';
            return;
        }
        vector<int> tmp;
        cnt = cnt - d[pos[i]];
        bool ok = 0;
        if (cnt == 0)
            tmp.push_back(pos[i]), ok = 1;

        for (int j = 0; j < q.size(); j++)
        {
            tmp.push_back(q[j]);
            if (q[j] > pos[i])
                cnt--;
            if (cnt == 0 && !ok)
                tmp.push_back(pos[i]), ok = 1;
        }
        q = tmp;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[q[i]] = i + 1;
    }
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}