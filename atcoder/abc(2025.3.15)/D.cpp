#include <bits/stdc++.h>
#define int long long
using namespace std;

int floorSqrt(int n)
{
    int x = sqrt(n);
    if (x * x > n)
    {
        x--;
    }
    return x;
}
int cmp(int d, int k)
{
    int v = 9 * d * d - 12 * (d * d - k);
    if (v < 0)
        return 0;
    int y = (-3 * d + floorSqrt(v)) / 6;
    if (3 * y * y + 3 * y * d + d * d == k)
        return y;
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int y = cmp(i, n / i);
            if (y)
            {
                cout << i + y << ' ' << y << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}