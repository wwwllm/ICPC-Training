#include <bits/stdc++.h>
#define int long long
using namespace std;

// 卡特兰数：ans=c[n][2*n]-c[n-1][2*n]=c[n][2*n]/(n+1)
const int N = 1e5 + 10, mod = 1e9 + 7;
int n;
int expower(int a, int b)
{
    a %= mod;
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
signed main()
{
    cin >> n;
    int a = 2 * n;
    int ans = 1;
    for (int i = 1, j = a; i <= n; i++, j--)
    {
        ans = ans * j % mod;
        ans = ans * expower(i, mod - 2) % mod;
    }
    ans = ans * expower(n + 1, mod - 2) % mod;
    cout << ans << endl;
    return 0;
}