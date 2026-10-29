#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    array<int, 2> cnt{0, 0}, mx{0, 0};
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i] & 1]++;
        mx[a[i] & 1] = max(mx[a[i] & 1], a[i]);
    }
    if (cnt[1] & 1)
    {
        int r = max(mx[0] - 1, mx[1]);
        cout << (r + 1) / 2 << '\n';
    }
    else
    {
        int r = max(mx[0], mx[1] - 1);
        cout << r / 2 << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
