#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int fact[N], p;
int expower(int a, int b, int mod)
{
    a %= mod;
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void init()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % mod;
}
int c(int a, int b)
{
    return fact[a] * expower(fact[b], p - 2, p) * expower(fact[a - b], p - 2, p);
}
int lucas(int a.int b)
{
    if (a < p && b < p)
        return c(a, b);
    return c(a % p, b % p) * lucas(a / p, b / p) % p;
}
signed main()
{
    init();
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }
    return 0;
}