#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    string s;
    cin >> s;
    s = ' ' + s;
    int l = -1, r = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '?')
            r = i;
    }
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == '?')
            l = i;
    }
    int c0 = 0, c1 = 0;
    {
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == ')')
                c1++;
            else if (s[i] == '(')
                c0++;
        }
        int d = c1 - c0;
        int cnt = r - l + 1;
        int R = cnt - d;
        c0 = R / 2 + d, c1 = R / 2;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '?')
        {
            if (c0 != 0)
            {
                s[i] = '(';
                c0--;
            }
            else
                s[i] = ')';
        }
    }
    int res = 0;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = (s[i] == '(' ? 1 : -1);
        p[i] += p[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == ')')
            res += p[i - 1];
    }
    if (res == m)
    {
        for (int i = 1; i <= n; i++)
            cout << s[i];
        cout << '\n';
    }
    else
    {
        int d = res - m;
        while (p[l - 1] <= 0)
            l++;
        int cur = p[l - 1];
        for (int i = r - c1 + 1; i <= r; i++)
        {
            if (d > (i - l))
            {
                d -= i - l;
                swap(s[i], s[l]);
            }
            else
            {
                int j = i - d;
                swap(s[j], s[i]);
                for (int i = 1; i <= n; i++)
                    cout << s[i];
                cout << '\n';
                return;
            }
            cur += (s[l++] == ')' ? -1 : 1);
            while (cur <= 0)
            {
                cur += (s[l++] == ')' ? -1 : 1);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
