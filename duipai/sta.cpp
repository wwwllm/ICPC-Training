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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    int x = 0;
    if (s.back() == 's')
    {
        for (int i = 0; i < n; i++)
            x += a[i], x %= mod;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            x = x * a[i] % mod;
        }
    }
    for (int i = k - 2; i >= 0; i--)
    {
        if (s[i] == 's')
            x = x * n % mod;
        else
            x = exp(x, n);
    }
    cout << x << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}