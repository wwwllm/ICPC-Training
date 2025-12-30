#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<array<int, 5>> a(n + 1);
    vector<char> ch(n + 1);
    map<array<int, 2>, char> p;
    auto cmp = [&](int x, int y, int pos) -> bool
    {
        auto [op, aa, b, c, d] = a[pos];
        if (op == 0)
        {
            int r1 = (x - aa) * (x - aa) + (y - b) * (y - b);
            if (r1 > c * c)
                return 0;
            else
            {
                p[{x, y}] = ch[pos];
                return 1;
            }
        }
        else if (op == 1)
        {
            if (x >= aa && x <= c && y >= b && y <= d)
            {
                p[{x, y}] = ch[pos];
                return 1;
            }
            else
                return 0;
        }
        return 0;
    };
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s == "Circle")
        {
            int x, y, r;
            char C;
            cin >> x >> y >> r >> C;
            a[i] = {0, x, y, r, 0};
            ch[i] = C;
        }
        else if (s == "Rectangle")
        {
            int x1, y1, x2, y2;
            char C;
            cin >> x1 >> y1 >> x2 >> y2 >> C;
            ch[i] = C;
            a[i] = {1, x1, y1, x2, y2};
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            for (int i = x1; i <= x2; i++)
            {
                for (int j = y1; j <= y2; j++)
                {
                    if (p.find({i, j}) == p.end())
                        p[{i, j}] = '.';
                }
            }
            a[i] = {2, x1, y1, x2, y2};
            ch[i] = '.';
        }
    }
    for (int k = 1; k <= n; k++)
    {
        if (a[k][0] == 2)
        {
            auto [op, x1, y1, x2, y2] = a[k];
            for (int j = y2; j >= y1; j--)
            {
                for (int i = x1; i <= x2; i++)
                {
                    bool ok = 0;
                    for (int kk = k - 1; kk >= 1; kk--)
                    {
                        if (cmp(i, j, kk))
                        {
                            cout << p[{i, j}];
                            ok = 1;
                            break;
                        }
                    }
                    if (ok == 0)
                        cout << p[{i, j}];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}