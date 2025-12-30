#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int ex_power(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void solve()
{
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i <= 9; i++)
    {
        int x;
        cin >> x;
        mp[i] = x;
    }
    if (n == 1)
    {
        if (mp[0])
        {
            cout << 0 << endl;
            return;
        }
    }
    int p;
    for (int i = 1; i <= 9; i++)
    {
        if (mp[i])
        {
            mp[i]--;
            p = i;
            break;
        }
    }
    const int k = ex_power(9, mod - 2);
    int ans = p * ex_power(10, --n) % mod;
    int i = 0;
    while (n > 0)
    {
        while (mp[i] == 0 && i < 10)
        {
            i++;
        }
        if (n <= mp[i])
        {
            ans = (ans + i * (ex_power(10, n) - 1) * k % mod) % mod;
            break;
        }
        else
        {
            ans = (ans + i * (ex_power(10, mp[i]) - 1) * k % mod * ex_power(10, n - mp[i]) % mod) % mod;
            n -= mp[i];
        }
        i++;
    }
    ans %= mod;
    cout << ans << endl;
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