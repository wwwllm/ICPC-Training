#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "YES\n"
             << a[0] << '\n';
        return;
    }
    vector<array<int, 26>> cnt(n);
    for (int i = 0; i < n; i++)
    {
        cnt[i].fill(0);
        for (auto c : a[i])
            cnt[i][c - 'a']++;
    }
    map<int, array<int, 26>> pre;
    for (int i = n - 1; i > 0; i--)
    {
        if (pre.count(a[i].size()))
        {
            if (pre[a[i].size()] != cnt[i])
            {
                cout << "NO\n";
                return;
            }
        }
        else
            pre[a[i].size()] = cnt[i];
        map<int, array<int, 26>> npre;
        for (const auto &[len, x] : pre)
        {
            int t = len / (a[i - 1].size());
            int r = len % (a[i - 1].size());
            array<int, 26> y;
            y.fill(0);
            for (int j = 0; j < 26; j++)
            {
                y[j] = x[j] - t * cnt[i - 1][j];
                if (y[j] < 0)
                {
                    cout << "NO\n";
                    return;
                }
            }
            if (r > 0)
            {
                if (npre.count(r))
                {
                    if (y != npre[r])
                    {
                        cout << "NO\n";
                        return;
                    }
                }
                else
                    npre[r] = y;
            }
            else
            {
                for (int j = 0; j < 26; j++)
                {
                    if (y[j] != 0)
                    {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
        pre = npre;
    }
    if (pre.count(a[0].size()))
    {
        if (pre[a[0].size()] != cnt[0])
        {
            cout << "NO\n";
            return;
        }
    }
    else
        pre[a[0].size()] = cnt[0];
    string s0 = "";
    array<int, 26> tmp;
    tmp.fill(0);
    for (const auto &[len, c] : pre)
    {
        auto cc = c;
        for (int j = 0; j < 26; j++)
        {
            cc[j] -= tmp[j];
            if (cc[j] < 0)
            {
                cout << "NO\n";
                return;
            }
        }
        for (int j = 0; j < 26; j++)
        {
            s0.append(cc[j], j + 'a');
        }
        tmp = c;
    }
    cout << "YES\n";
    string s = s0;
    cout << s << '\n';
    for (int i = 1; i < n; i++)
    {
        int t = a[i].size() / s.size();
        int r = a[i].size() % s.size();
        string res = "";
        for (int j = 0; j < t; j++)
        {
            res += s;
        }
        for (int j = 0; j < r; j++)
            res += s[j];
        cout << res << '\n';
        s = res;
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