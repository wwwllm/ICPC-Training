#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2065/C2
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(b.begin(), b.end());
    bool flag = 1;
    auto find = [&](int a1, int a2) -> int
    {
        int l = -1, r = m;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (a1 <= b[mid] - a2)
                r = mid;
            else
                l = mid;
        }
        return r;
    };
    a[0] = min(b[0] - a[0], a[0]);
    for (int i = 1; i < n; i++)
    {
        int pos = find(a[i - 1], a[i]);
        if (a[i] < a[i - 1])
        {
            if (pos == m)
            {
                flag = 0;
                break;
            }
            else
                a[i] = b[pos] - a[i];
        }
        else
        {
            if (pos != m)
                a[i] = min(a[i], b[pos] - a[i]);
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
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