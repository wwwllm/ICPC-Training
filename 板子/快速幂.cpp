#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod_exp(int base, int exponent, int mod)
{
    int result = 1;
    base = base % mod; // 防止base本身就大于mod

    while (exponent > 0)
    {
        // 如果 exponent 是奇数，将 base 乘入结果
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }

        // exponent 是偶数，将 base 平方并减半 exponent
        exponent = exponent >> 1; // 等价于 exponent /= 2
        base = (base * base) % mod;
    }

    return result;
}

signed main()
{
    int a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod "<<p<< "=" << mod_exp(a, b, p) << endl;
}