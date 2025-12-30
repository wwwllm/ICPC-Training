#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int mex = 0;
    for (auto x : a)
    {
        if (x == mex)
            mex++;
        else if (x > mex)
            break;
    }
    vector<int> cnt(n + 1), sum(n + 1);
    for (auto x : a)
        cnt[x]++;
    sum[0] = cnt[0];
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + cnt[i];
    }
    vector<array<int, 2>> q(mex + 1);
    vector<int> ans(n + 2);
    q[mex] = {0, n - mex};
    q[0][0] = cnt[0], q[0][1] = n;
    for (int i = 1; i < mex; i++)
    {
        q[i][0] = cnt[i];
        q[i][1] = n - i;
    }
    for (auto [l, r] : q)
    {
        ans[l]++;
        ans[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        ans[i] += ans[i - 1];
    for(int i=0;i<=n;i++)
        cout << ans[i] << " \n"[i == n];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}