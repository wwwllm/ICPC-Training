#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (!a && !b)
    {
        if (c)
            cout << -1 << '\n';
        else
            cout << 0 << '\n';
        return;
    }
    if (a == b && b == c)
    {
        cout << 0 << '\n';
        return;
    }
    int lena, lenb, lenc;
    vector<int> res;
    auto getlen = [&](int x) -> int
    {
        for (int i = 30; i >= 0; i--)
        {
            if ((x >> i) & 1)
            {
                return i + 1;
            }
        }
        return 0;
    };
    lena = getlen(a), lenb = getlen(b), lenc = getlen(c);
    if (lena > lenb)
    {
        b = a ^ b;
        res.push_back(4);
        lenb = lena;
    }
    else if (lena < lenb)
    {
        a = b ^ a;
        res.push_back(3);
        lena = lenb;
    }
    if (lenc <= lena)
    {
        for (int i = lenb - 1; i >= 0; i--)
        {
            int u = (a >> i) & 1, v = (c >> i) & 1;
            if (u == v)
            {
                res.push_back(2);
                b >>= 1;
            }
            else
            {
                res.push_back(3);
                res.push_back(2);
                a = a ^ b;
                b >>= 1;
            }
        }
        res.push_back(4);
        b = b ^ a;
        cout << res.size() << '\n';
        for (auto op : res)
        {
            cout << op << ' ';
        }
        cout << '\n';
        return;
    }
    // cout << a << ' ' << b << '\n';
    for (int i = lena - 1, j = lenc - 1; i >= 0; i--, j--)
    {
        int u = (a >> i) & 1, v = (c >> j) & 1;
        if (u == v)
        {

            if (i)
            {
                res.push_back(2);
                b >>= 1;
            }
        }
        else
        {
            if (i)
            {
                res.push_back(3);
                res.push_back(2);
                a = a ^ b;
                b >>= 1;
            }
            else
            {
                res.push_back(3);
                a = a ^ b;
            }
        }
    }
    for (int j = lenc - lena - 1; j >= 0; j--)
    {
        int u = (c >> j) & 1;
        res.push_back(1);
        a <<= 1;
        if (u)
        {
            res.push_back(3);
            a = a ^ b;
        }
    }
    res.push_back(2);
    b >>= 1;
    res.push_back(4);
    b = a ^ b;
    cout << res.size() << '\n';
    for (auto op : res)
        cout << op << ' ';
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