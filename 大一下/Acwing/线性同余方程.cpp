#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, m, x, y;
        cin >> a >> b >> m;
        int d = exgcd(a, m, x, y);
        if (b % d)
            cout << "impossible" << endl;
        else
            x = (ll)x * b / d % m,cout << x << endl;
    }
    return 0;
}