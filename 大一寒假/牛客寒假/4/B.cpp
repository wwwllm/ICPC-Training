#include <bits/stdc++.h>
#define int long long
using namespace std;

// 01--11--00
// 011--111--001--010
// 111--011--010--110
// 010--110--000--011
const int maxn = 2e5 + 50, mod = 1e9 + 7;
char a[maxn];
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
void solve()
{
    int n;
    cin >> n;
    int p = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == '?')
            p++;
    }
    if(n==1){
        if(a[1]=='?')
            cout << 2 << endl;
        else
            cout << 1 << endl;
        return;
    }
    if (a[1] != '?' && a[n] != '?' && a[1] == a[n])
    {
        ans = ((n - 2) * mod_exp(2, p)) % mod;
    }
    else if (a[1] != '?' && a[n] != '?' && a[1] != a[n])
    {
        ans = (2 * mod_exp(2, p)) % mod;
    }
    else
    {
            ans = ((n - 2) * mod_exp(2, p - 1) + 2 * mod_exp(2, p - 1)) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}