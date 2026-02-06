#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == (1LL << (__builtin_ctz(n))))
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n + 1);
    ans[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = ans[n] ^ i;
    }
    if (n & 1)
        ans[1] = n ^ 1;
    else
    {
        ans[1] = n;
        for (int i = 2; i <= n; i++)
        {
            if ((i ^ n) <= n)
            {
                swap(ans[1], ans[i]);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
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