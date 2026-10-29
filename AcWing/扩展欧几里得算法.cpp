#include <bits/stdc++.h>
using namespace std;

// 裴蜀定理：对于任意一对正整数a,b，一定存在非零整数x,y使得a*x+b*y==gcd(a,b)
//  int gcd(int a, int b)欧几里得算法
//  {
//      return !b ? a : gcd(b, a % b);
//  }
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
    while (n--)
    {
        int a, b, x, y;
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}