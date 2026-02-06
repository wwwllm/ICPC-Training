#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 1e9 + 7, N = 2e5;
int exp(int a, int b, int p)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
int inv(int x, int p)
{
    return exp(x, p - 2, p);
}
void solve()
{
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    s = ' ' + s;
    if (s[1] == '?')
        s[1] = '1';
    if (s[n] == '?')
        s[n] = '1';
    if (s[1] == '0' || s[n] == '0')
    {
        cout << -1 << '\n';
        return;
    }
    int ans = 1, ans_c = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '0')
            ans = ans * (i - 1) % mod, ans_c = ans_c * (i - 1) % c;
        else if (s[i] == '1')
            ans = ans * 2 % mod, ans_c = ans_c * 2 % c;
        else if (s[i] == '?' && (i & 1))
        {
            ans = ans * 2 % mod;
            ans_c = ans_c * 2 % c;
        }
    }
    for (int i = n - 1; i >= 3; i--)
    {
        if (s[i] == '?' && !(i & 1))
        {
            if (ans_c * 2 % c != 0)
            {
                ans = ans * 2 % mod;
                ans_c = ans_c * 2 % c;
            }
            else
            {
                ans = ans * (i - 1) % mod;
                ans_c = ans_c * (i - 1) % c;
            }
        }
    }
    if (ans_c)
    {
        cout << ans << '\n';
    }
    else
        cout << -1 << '\n';
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