#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P3805
struct Manacher
{
    int n;
    string s;
    vector<int> r;
    Manacher(string _s)
    {
        s = '#';
        for (auto c : _s)
        {
            s += c, s += '#';
        }
        n = s.size();
        r.resize(n);
        init();
    }
    void init()
    {
        for (int i = 0, c = 0; i < n; i++)
        {
            if (2 * c - i >= 0 && c + r[c] > i)
            {
                r[i] = min(r[2 * c - i], c + r[c] - i);
            }
            while (i - r[i] >= 0 && i + r[i] < n && s[i - r[i]] == s[i + r[i]])
            {
                r[i]++;
            }
            if (i + r[i] > c + r[c])
                c = i;
        }
    }
    int get_max()
    {
        int res = 0;
        for (int l : r)
        {
            res = max(res, l - 1);
        }
        return res;
    }
    bool check(int x, int y)
    {
        int nl = x * 2 + 1;
        int nr = y * 2 + 1;
        int mid = nl + nr >> 1;
        return r[mid] - 1 >= y - x + 1;
    }
};
void solve()
{
    string s;
    cin >> s;
    Manacher m(s);
    cout << m.get_max() << '\n';
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