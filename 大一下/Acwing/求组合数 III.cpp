#include <bits/stdc++.h>
#define int long long
using namespace std;

// lucas定理：c[a,b]==c[a%p][b%p]*c[a/p][b/p](mod p)
const int N = 1e5 + 10;
int p;
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
int c(int a, int b)
{
    int ans = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        ans = (ans * j) % p;
        ans = (ans * expower(i, p - 2, p)) % p;
    }
    return ans;
}
int lucas(int a,int b)
{
    if (a < p && b < p)
        return c(a, b);
    return c(a % p, b % p) * lucas(a / p, b / p) % p;
}
signed main()
{
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