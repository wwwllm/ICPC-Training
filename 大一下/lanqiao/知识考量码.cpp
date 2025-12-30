#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int mod_exp(int base, int exponent)
{
    int result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }

    return result;
}
int cnt[32], c[32][32];//c为组合数
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
    }
    for (int i = 31, p = 0; i >= -1; i--)
    {
        if (i == -1)
        {
            cnt[p] += 1;
        }
        else if (k >> i & 1)//当第i位为1是0-i-1位都可以为一
        {
            for (int j = 0; j <= i; j++)
            {
                cnt[p + j] = (cnt[p + j] + c[i][j]) % mod;
            }
            p += 1;
        }
    }
    int ans = 0;
    for (int i = 1; i < 32; i++)
    {
        ans = (ans + cnt[i] * mod_exp(n, i)) % mod;
    }
    ans++;
    ans %= mod;
    cout << ans << endl;
    return 0;
}