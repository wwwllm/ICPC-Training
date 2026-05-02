#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> p(k);
    for (int i = 0; i < k; i++)
        cin >> p[i];
    int pp = p[0] - 1;
    int res1 = 0;
    for (int i = p[0]; i < n; i++)
    {
        if (a[i] != a[i - 1])
            res1++;
    }
    res1 += !(a.back() == a[pp]);
    int res2 = 0;
    for (int i = pp - 1; i >= 0; i--)
    {
        if (a[i] != a[i + 1])
            res2++;
    }
    res2 += !(a[0] == a[pp]);
    cout << max(res1, res2) << '\n';
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