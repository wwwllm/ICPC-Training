#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105922
const int mod = 998244353;
int exp(int a, int b)
{
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
void solve()
{
    int n, m;
    cin >> n >> m;
    if (m & 1)
    {
        swap(n, m);
    }
    if (n & 1)
    {
        if (m & 1)
        {
            cout << exp(2, n + m - 2) << '\n';
        }
        else
        {
            cout << exp(2, m - 1) << '\n';
        }
    }
    else
    {
        if (m & 1)
            cout << exp(2, n - 1) << '\n';
        else
            cout << 1 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}