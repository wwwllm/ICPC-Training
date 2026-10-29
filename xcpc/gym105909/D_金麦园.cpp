#include <bits/stdc++.h>
#define int long long
using namespace std;
using ull = unsigned long long;

// https://codeforces.com/gym/105909
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ranges::sort(a);
    auto check = [&](int x) -> int
    {
        int res = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            int r = a[i] + x;
            while (j < n && a[j] <= r)
                j++;
            res += j - i - 1;
        }
        return res;
    };
    int l = -1, r = *ranges::max_element(a) - *ranges::min_element(a);
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid) >= k)
            r = mid;
        else
            l = mid;
    }
    if (l == -1)
    {
        cout << k * r << '\n';
        return;
    }
    vector<ull> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    int c = check(l);
    ull ans = 0;
    for (int i = 0; i < n; i++)
    {
        int R = a[i] + l;
        int pos = ranges::upper_bound(a, R) - a.begin();
        ull tmp = pre[pos - 1] - pre[i];
        ull len = pos - i - 1;
        ans += tmp - len * a[i];
    }
    ans += (k - c) * r;
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