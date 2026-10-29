#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
vector<int> kmp(string s)
{
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j])
        {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}

vector<int> match(string s, string p)
{
    int n = s.size(), m = p.size();
    auto f = kmp(p);
    vector<int> pos;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j && s[i] != p[j])
            j = f[j];

        j += (s[i] == p[j]);
        if (j == m)
        {
            pos.push_back(i - m + 1);
            j = f[j];
        }
    }
    if (p == "")
    {
        pos.push_back(0);
    }
    return pos;
}
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<string> g;
    string cur = "";
    vector<int> len;
    if (ranges::count(s, '*') == n)
    {
        cout << m * (m + 1) / 2 << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            g.push_back(cur);
            len.push_back(cur.size());
            cur = "";
            while (i < n && s[i + 1] == '*')
                i++;
        }
        else
        {
            cur += s[i];
        }
    }
    g.push_back(cur);
    len.push_back(cur.size());
    int cnt = g.size();
    vector pos(cnt, vector<int>());
    for (int i = 0; i < cnt; i++)
    {
        pos[i] = match(t, g[i]);
    }
    if (cnt == 1)
    {
        cout << pos[0].size() << '\n';
        return;
    }
    vector nxt(cnt, vector<int>(m + 1, m + 1));
    for (int i = 0; i < cnt; i++)
    {
        for (auto l : pos[i])
        {
            nxt[i][l] = l;
        }
        for (int j = m - 1; j >= 0; j--)
        {
            nxt[i][j] = min(nxt[i][j + 1], nxt[i][j]);
        }
    }
    vector<int> suf(m + 1);
    for (auto l : pos.back())
    {
        suf[l] = 1;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        suf[i] += suf[i + 1];
    }
    int res = 0;
    for (auto l : pos[0])
    {
        int p = l;
        for (int i = 0; i < cnt - 1 && p <= m; i++)
        {
            p = nxt[i][p];
            p += len[i];
        }
        if (p <= m)
        {
            res += suf[p];
        }
    }
    cout << res << '\n';
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