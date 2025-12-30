#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2065/D
vector<int> add(vector<int> a)
{
    int len = a.size();
    vector<int> s(len);
    s[0] = a[0];
    for (int i = 1; i < len; i++)
        s[i] = s[i - 1] + a[i];
    return s;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> sum(n), a(m), sum1(n);
    for (int i = 0; i < n; i++)
    {
        for (auto &x : a)
            cin >> x;
        a = add(a);
        sum[i] = a.back();
        int res = 0;
        for (auto it : a)
            res += it;
        sum1[i] = res;
    }
    sort(sum.begin(), sum.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (n - i - 1) * m * sum[i];
    }
    for (auto it : sum1)
        ans += it;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}