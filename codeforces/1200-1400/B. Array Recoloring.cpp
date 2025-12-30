#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2075/B
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    if (k > 1)
    {
        sort(a.begin(), a.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i <= k; i++)
            sum += a[i];
        cout << sum << '\n';
    }
    else
    {
        int pre = *max_element(a.begin(), a.end() - 1);
        int suf = *max_element(a.begin() + 1, a.end());
        int ans = max(pre + a[n - 1], suf + a[0]);
        cout << ans << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}