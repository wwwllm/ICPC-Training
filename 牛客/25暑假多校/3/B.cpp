#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (!a && !b && c)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> res;
    auto swapab = [&]()
    {
        swap(a, b);
        res.push_back(3);
        res.push_back(4);
        res.push_back(3);
    };
    int p = -1;
    for (int i = 30; i >= 0; i--)
    {
        if ((a >> i) & 1)
        {
            p = i;
            break;
        }
    }

    for (int i = p; i <= 29; i++)
    {
        res.push_back(1);
        a <<= 1;
    }
    swapab();
    for (int i = 30; i >= 0; i--)
    {
        int u = (a >> i) & 1, v = (c >> i) & 1;
        if (u == v)
        {
            res.push_back(2);
        }
        else
        {
            res.push_back(3);
            res.push_back(2);
            a = a ^ b;
        }
        b >>= 1;
    }
    res.push_back(4);
    b = b ^ a;
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