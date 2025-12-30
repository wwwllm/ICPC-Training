#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2032/C
// 对于一个数组a[],数组有序
// a[1]+a[2]>a[n]则任取三个数都可以组成三角形
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = n;
    for (int i = 0, j = 1; i < n; i++)
    {
        int u = a[i] + a[i + 1];
        while (j < n && a[j] < u)
            j++;
        int res = i + n - j;
        ans = min(res, ans);
    }
    cout << ans << '\n';
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