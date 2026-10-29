#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int N = 320;
    vector f(N + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= N; k++)
        {
            f[k][i] = gcd(a[i], k) * gcd(a[i], k);
        }
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[k][i] += f[k][i - 1];
        }
    }
    vector cnt1(N + 1, vector<int>(n + 1));
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % k == 0)
            {
                cnt1[k][i] = gcd(a[i] / k, k) == 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cnt1[k][i] += cnt1[k][i - 1];
        }
    }
    vector cnt2(N + 1, vector<int>(n + 1));
    
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (k <= N)
        {
            cout << f[k][r] - f[k][l - 1] << '\n';
        }
        else
        {
            int res = 0;
            for (int i = 1; i <= k / i; i++)
            {
                if (i <= N)
                {
                    int c = cnt1[i][r] - cnt1[i][l - 1];
                    res += i * i * c;
                }
                else
                {
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
