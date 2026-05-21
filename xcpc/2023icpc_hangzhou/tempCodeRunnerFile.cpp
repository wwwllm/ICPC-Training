#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    auto query = [&](int u, int v) -> int
    {
        cout << u << ' ' << v << endl;
        int res;
        cin >> res;
        return res;
    };
    auto answer = [&](int x)
    {
        cout << "! " << x << endl;
    };
    int res;
    array<int, 2> e = {-1, -1};
    for (int i = 1; i + 1 <= n; i += 2)
    {
        int u = i, v = i + 1;
        res = query(u, v);
        if (res == 1)
        {
            e = {u, v};
            break;
        }
    }
    if (n & 1 && e == array<int, 2>{-1, -1})
    {
        res = query(n, n - 1);
        if (res == 1)
            e = {n, n - 1};
    }
    if (e == array<int, 2>{-1, -1})
    {
        answer(1);
        return;
    }
    else
    {
        int c = -1;
        vector<int> p;
        for (int i = 1; i <= n; i++)
        {
            if (i != e[1] && i != e[0])
            {
                p.push_back(i);
            }
            if (p.size() == 2)
                break;
        }
        res = query(p[0], e[0]);
        if (res)
        {
            c = e[0];
        }
        else
        {
            res = query(p[0], e[1]);
            if (res)
            {
                answer(1);
                return;
            }
            c = e[1];
        }
        res = query(p[1], c);
        if (res)
            answer(2);
        else
            answer(1);
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