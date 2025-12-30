#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = abs(x);
    }
    int pos = (n + 1) / 2;
    int res = a[1];
    sort(a.begin() + 1, a.end());
    auto find = [&](int x)
    {
        int l = 0, r = n + 1;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= x)
                r = mid;
            else
                l = mid;
        }
        return r;
    };
    int p = find(res);
    if (!(n & 1))
        pos++;
    if (p <= pos)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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