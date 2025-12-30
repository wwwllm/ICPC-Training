#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, sum += x;
    sort(a.begin(), a.end());
    a[n - 1]--;
    sort(a.begin(), a.end());
    if (a[n - 1] - a[0] > k || sum % 2 == 0)
        cout << "Jerry\n";
    else
        cout << "Tom\n";
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