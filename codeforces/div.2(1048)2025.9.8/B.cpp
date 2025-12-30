#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int cnt = m;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (cnt >= 0)
        {
            sum += cnt * a[i];
            cnt--;
        }
    }
    cout << sum << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}