#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105423
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    int ma = 1LL << 18;
    vector<int> f(ma);
    for (int i = 0; i < n; i++)
    {
        int msk = 0;
        int j = i;
        vector<int> cnt(19);
        while (j < n && !cnt[a[j]])
        {
            msk |= 1LL << a[j];
            f[msk] = max(f[msk], j - i + 1);
            cnt[a[j]] = 1;
            j++;
        }
    }
    for (int i = 1; i < ma; i++)
    {
        for (int j = 0; j < 18; j++)
            if ((i >> j) & 1)
                f[i] = max(f[i], f[i ^ (1LL << j)]);
    }
    int ans = 0;
    for (int i = 0; i < ma; i++)
    {
        ans = max(ans, f[i] + f[(ma - 1) ^ i]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}