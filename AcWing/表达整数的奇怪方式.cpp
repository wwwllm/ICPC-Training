#include <bits/stdc++.h>
#define int long long
using namespace std;

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
    int n;
    cin >> n;
    int a1, m1;
    cin >> a1 >> m1;
    bool flag = 1;
    for (int i = 1; i < n; i++)
    {
        int a2, m2, x, y;
        cin >> a2 >> m2;
        int d = exgcd(a1, a2, x, y);
        if ((m2 - m1) % d)
        {
            flag = 0;
            break;
        }
        x *= (m2 - m1) / d;
        int t = a2 / d;
        x = (x % t + t) % t; // 将x变成最小正整数解
        m1 = a1 * x + m1;
        a1 = abs(a1 / d * a2);
    }
    if (!flag)
        cout << -1<< endl;
    else
        cout << (m1 % a1 + a1) % a1 << endl;
    return 0;
}