#include <bits/stdc++.h>
#define int long long
using namespace std;

//[n^2,(n+1)^2]--n
const int mod = 998244353;
void solve()
{
    int x;
    cin >> x;
    int k = (int)sqrt(x);
    int sum = ((k - 1) % mod * k % mod * (k + 1) % mod + k * k) % mod;
    if(k*k+k<=x)
        sum = (sum + k * k + k) % mod;
    if (k * k + 2*k <= x)
        sum = (sum + k * k + 2*k) % mod;
    cout << sum << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t  ;
    cin >> t;
    while (t--)
        solve();
    return 0;
}