#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> cnt(n + 1);
    int ans = 0;
    for (int i = 0; i <= 31; i++)
    {
        vector<array<int, 2>> c(2);
        for (int j = 1; j <= n; j++)
        {
            int u = (a[j] >> i) & 1;
            c[cnt[j] & 1][u]++;
            cnt[j] += u;
        }
        ans += (c[0][0] * c[0][1] + c[1][1] * c[1][0]) * (1LL << i);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}