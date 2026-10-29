#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105143
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    vector<int> a(n);
    int ans = 0;
    for (int k = 31; k >= 0; k--)
    {
        int tmp = n * ((1LL << k) - 1);
        if (sum <= tmp)
            continue;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (sum >= (1LL << k))
                    a[i] += (1LL << k), sum -= (1LL << k);
            }
            ans += (1LL << k);
        }
    }
    cout << ans << '\n';
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