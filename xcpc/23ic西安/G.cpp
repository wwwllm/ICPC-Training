#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
                cnt++, n /= i;
            ans *= (2 * cnt + 1);
        }
    }
    if (n != 1)
        ans *= 3;
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % (i * i) == 0)
            cnt++;
    }
    cout << (ans + cnt) / 2 << '\n';
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
