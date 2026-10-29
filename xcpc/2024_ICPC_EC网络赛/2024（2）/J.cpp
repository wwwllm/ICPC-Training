#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105358
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (auto &[w, v, c] : a)
        cin >> w >> v >> c;
    ranges::sort(a, [&](array<int, 3> &a, array<int, 3> &b)
                 { return a[0] * b[2] > b[0] * a[2]; });
    int d = 0;
    int sum = 0, pre = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i][1];
        d += pre * a[i][2];
        pre += a[i][0];
    }
    cout << sum - d << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}