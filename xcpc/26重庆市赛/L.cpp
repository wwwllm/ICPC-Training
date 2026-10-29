#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    auto query = [&](int op) -> string
    {
        int c = 0;
        for (int i = 1; i <= n; i++)
        {
            c += cnt[i] == op;
        }
        cout << "? " << c << ' ';
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] == op)
                cout << i << ' ';
        }
        cout << endl;
        string res;
        cin >> res;
        return res;
    };
    auto answer = [&](int x, int y)
    {
        cout << "! " << x << ' ' << y << endl;
    };
    vector<int> dif(10), ok(10, -1);
    string res;
    for (int i = 0; i <= 9; i++)
    {
        cnt.assign(n + 1, 0);
        int c = 0;
        for (int k = 1; k <= n; k++)
        {
            if ((k >> i) & 1)
                cnt[k] = 1, c++;
        }
        if (c == 0)
            continue;
        if (query(1) == "YES")
            dif[i] = 1, ok[i] = 1;
        else if (query(0) == "YES")
            dif[i] = 1, ok[i] = 0;
    }
    vector<int> can(n + 1, 1);
    for (int i = 0; i <= 9; i++)
    {
        if (ok[i] == -1)
            continue;
        for (int k = 1; k <= n; k++)
        {
            if (((k >> i) & 1) == ok[i])
                can[k] &= 1;
            else
                can[k] = 0;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        if (ok[i] != -1)
            continue;
        cnt.assign(n + 1, 0);
        int c = 0;
        for (int k = 1; k <= n; k++)
        {
            if (can[k] == 1 && ((k >> i) & 1))
                cnt[k] = 1, c++;
        }
        if (c == 0)
        {
            ok[i] = 0;
            continue;
        }
        res = query(1);
        if (res == "YES")
            ok[i] = 1;
        else
            ok[i] = 0;
    }
    int x = 0, y = 0;
    for (int i = 0; i <= 9; i++)
    {
        int u = ok[i], v = dif[i] ? !ok[i] : ok[i];
        x += u << i, y += v << i;
    }
    answer(x, y);
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