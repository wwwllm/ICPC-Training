#include <bits/stdc++.h>
using namespace std;

int a[200];
set<int> S;
void solve()
{
    int n, p;
    S.clear();
    cin >> n >> p;
    for (int i = n; i >= 1; i--)
        cin >> a[i], S.insert(a[i]);
    a[n + 1] = 0;
    int l = 0, r = p - 1;
    while (S.count(l))
        l++;
    while (S.count(r))
        r--;
    if (l == p)
    {
        cout << 0 << endl;
        return;
    }
    if (a[1] <= l)
    {
        cout << r - a[1] << endl;
    }
    else
    {
        int sum1 = p - a[1], r1 = a[1];
        a[1] = p;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= p)
            {
                a[i] %= p;
                a[i + 1]++;
                S.insert(a[i + 1]);
            }
            else
            {
                break;
            }
        }
        while (S.count(r1))
            r1--;
        r1 = max(0, r1);
        int ans = sum1 + r1;
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
