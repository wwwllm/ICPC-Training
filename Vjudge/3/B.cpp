#include <bits/stdc++.h>
#define int long long
using namespace std;

struct score
{
    int ti = 0, pos = 0, s = 0;
};
bool cmp(score a, score b)
{
    if (a.ti == b.ti && a.s == b.s)
        return a.pos < b.pos;
    return a.s == b.s ? a.ti < b.ti : a.s > b.s;
}
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<score> s(n);
    vector<vector<int>> p(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> p[i][j];
    for (int i = 0; i < n; i++)
    {
        sort(p[i].begin(), p[i].end());
        s[i].pos = i + 1;
        for (int j = 1; j < m; j++)
            p[i][j] += p[i][j - 1];
        for (int j = 0; j < m; j++)
        {
            if (p[i][j] <= h)
            {
                s[i].s++;
                s[i].ti += p[i][j];
            }
            else
                break;
        }
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if (s[i].pos == 1)
        {
            cout << i + 1 << endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
