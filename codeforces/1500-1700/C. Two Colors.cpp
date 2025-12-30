#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2075/C
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), suf(m + 1);
    for (auto &X : a)
        cin >> X;
    sort(a.begin(), a.end());
    suf[m - 1] = min(n - 1, a[m - 1]);
    int ans = 0;
    for (int i = m - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + min(n - 1, a[i]);
    for (int i = 0, j = m - 1; i < m; i++)
    {
        while (j >= 0 && a[i] + a[j] >= n)
            j--;
        int res = 0;
        res = (m - j - 1) * (min(a[i], n - 1) - n + 1) + suf[j + 1];
        if (i >= j + 1)
        {
            res -= 2 * min(a[i], n - 1) - n + 1;
        }
        ans += res;
    }
    cout << ans << '\n';
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