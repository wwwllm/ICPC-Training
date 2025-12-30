#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int l = 0, r = n + 1;
    auto check = [&](int x)
    {
        int lpos = min_element(a.begin(), a.begin() + x) - a.begin(), rpos = max_element(a.begin() + x, a.end()) - a.begin();
        if (a[lpos] < a[rpos] && x != n)
            swap(a[lpos], a[rpos]);
        int mina = *min_element(a.begin(), a.begin() + x);
        int minb = *min_element(b.begin(), b.begin() + n - x + 1);
        if (a[rpos] < a[lpos] && x != n)
            swap(a[lpos], a[rpos]);
        return mina > minb;
    };
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
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