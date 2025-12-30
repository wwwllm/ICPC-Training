#include <bits/stdc++.h>
#define int long long
using namespace std;

int ex_power(int a, int b, int mod)//快速幂求逆元
{
    int ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int exgcd(int a, int b, int &x, int &y)//扩展欧几里得求逆元：a*x==1(mod p)
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
        int a, p;
        cin >> a >> p;
        if (a % p == 0)
            cout << "impossible" << endl;
        else
            cout << (ex_power(a, p - 2, p)) << endl;
    }
    return 0;
}