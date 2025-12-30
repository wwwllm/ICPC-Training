#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7, N = 1e4 + 10;
char a[N];
int b[N];
ll p[N], q[N];
ll expower(ll a, ll b)
{
    a %= mod;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
ll c(int a, int b)
{
    ll ans = 1;
    for (int i = 1, j = a; i <= b; i++, j--)
    {
        ans = (ans * j) % mod;
        ans = (ans * expower(i, mod - 2)) % mod;
    }
    return ans;
}
signed main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 'a')
            cnt++;
    }
    int ans = 0;
    if (cnt >= k)
    {
        ans = c(cnt, k);
        cout << ans << endl;
    }
    else
    {
        int x = k - cnt;
        int i = n + 1;
        while (x)
        {
            int j = i - 1;
            while (a[j] == 'b' && j > 0)
                j--;
            int res = i - j - 1;
            i = j;
            if (res < x)
                x -= res;
            else
            {
                ans =c(res, x);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}