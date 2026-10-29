#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500;
void solve()
{
    int l, r, n;
    cin >> l >> r >> n;
    int ans = r - l + 1;
    vector<int> p;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            p.push_back(i);
        }
    }
    if (n != 1)
        p.push_back(n);
    auto calc = [&](int r)
    {
        int m = p.size();
        int ans = 0;
        for (int b = 1; b < (1LL << m); b++)
        {
            int cnt = 0;
            int q = 1;
            for (int k = 0; k < m; k++)
            {
                if ((b >> k) & 1)
                {
                    cnt++;
                    q *= p[k];
                }
            }
            ans += cnt & 1 ? r / q : -r / q;
        }
        return ans;
    };
    cout << ans + calc(r) - calc(l - 1) << '\n';
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