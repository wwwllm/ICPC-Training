#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 998244353;
int dig[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> p(7);
    int iv100 = inv(100);
    for (int i = 0; i < 7; i++)
    {
        cin >> p[i];
        p[i] *= iv100;
        p[i] %= mod;
    }
    vector<int> q(10);
    for (int d = 0; d <= 9; d++)
    {
        int cur = 1;
        for (int i = 0; i < 7; i++)
        {
            if (dig[d][i] == 1)
                cur = cur * p[i] % mod;
            else
                cur = cur * (1 - p[i] + mod) % mod;
        }
        q[d] = cur;
    }
    auto clac = [&](int x) -> int
    {
        int res = 1;
        for (int i = 0; i < 4; i++)
        {
            int d = x % 10;
            x /= 10;
            res = res * q[d] % mod;
        }
        return res;
    };
    int ans = 0;
    for (int a = 0; a <= n; a++)
    {
        int b = n - a;
        ans = clac(b) * clac(a) % mod + ans;
        ans %= mod;
    }
    cout << ans << '\n';
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