#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2062/C
void solve()
{
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, ans += x;
    if (n == 1)
    {
        cout << ans << '\n';
        return;
    }
    while (a.size() > 1)
    {
        vector<int> temp;
        int n = a.size();
        sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            temp.push_back(a[i + 1] - a[i]);
            sum += a[i + 1] - a[i];
        }
        ans = max(ans, abs(sum));
        a = temp;
    }
    cout << ans << endl;
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