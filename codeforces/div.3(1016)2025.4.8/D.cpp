#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int f1(int x, int y, int n)
{
    if (x == 1 && y == 1)
        return 1;
    int ans = 0;
    int p = 1LL << (n - 1), t = 1LL << (2 * n - 2);
    if (x <= p && y <= p)
        ans += f1(x, y, n - 1);
    else if (x > p && y <= p)
        ans += f1(x - p, y, n - 1) + 2 * t;
    else if (x <= p && y > p)
        ans += f1(x, y - p, n - 1) + 3 * t;
    else
        ans += f1(x - p, y - p, n - 1) + t;
    return ans;
}
void solve()
{
    cin >> n;
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "->")
        {
            int x, y;
            cin >> x >> y;
            cout << f1(x, y, n) << endl;
        }
        else
        {
            int d;
            cin >> d;
            int x = 1, y = 1;
            int k = n;
            while (d != 1)
            {
                if (d <= (1LL << (2 * k - 2)))
                    k--;
                else if (d <= 2 * (1LL << (2 * k - 2)))
                {
                    x += (1LL << (k - 1)), y += (1LL << (k - 1));
                    d -= (1LL << (2 * k - 2));
                    k--;
                }
                else if (d <= 3 * (1LL << (2 * k - 2)))
                {
                    x += (1LL << (k - 1));
                    d -= 2 * (1LL << (2 * k - 2));
                    k--;
                }
                else
                {
                    y += (1LL << (k - 1));
                    d -= 3 * (1LL << (2 * k - 2));
                    k--;
                }
            }
            cout << x << ' ' << y << endl;
        }
    }
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