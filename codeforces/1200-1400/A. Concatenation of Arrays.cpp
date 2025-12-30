#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2023/A
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }
    sort(a.begin(), a.end(), [&](array<int, 2> aa, array<int, 2> bb)
         {
            auto [a,b]=aa;
            auto [c, d] = bb;
            if (max(a, b) == max(c, d))
            {
                return a + b < c + d;
            }
        else
            return max(a, b) < max(c, d); });
    for (auto it : a)
        cout << it[0] << ' ' << it[1] << ' ';
    cout << '\n';
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