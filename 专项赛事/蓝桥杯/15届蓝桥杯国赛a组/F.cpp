#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int exp(int a, int b)
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
    int x, y, n;
    cin >> x >> y >> n;
    bool ok = 1;
    map<int, int> mp;
    y /= x;
    if(y%x!=0){
        cout<<0<<'\n';
        return;
    }
    for (int i = 2; i <= y / i; i++)
    {
        if (y % i == 0)
        {
            while (y % i == 0)
            {
                mp[i]++;
                y /= i;
            }
        }
    }
    if (y != 1)
        mp[y]++;
    int ans = 1;
    for (auto [x, cnt] : mp)
    {
        if (cnt == 0)
            continue;
        else
        {
            int res = (exp(cnt + 1, n) - 2 * exp(cnt, n) + exp(cnt - 1, n) + mod * 2) % mod;
            ans = (ans * res) % mod;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}