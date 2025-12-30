#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> mul(vector<int> &a, int b)
{
    vector<int> ans;
    for (int i = 0, t = 0; i < a.size() || t; i++)
    {
        if (i < a.size())
            t += a[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (ans.size() > 1 && !ans.back())
        ans.pop_back();
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> res(1, 1);
    while (n--)
    {
        int b;
        cin >> b;
        res = mul(res, b);
        if (res.size() > k)
            res.assign(1, 1);
    }
    int len = res.size();
    if (len <= k)
        for (int i = len - 1; i >= 0; i--)
            cout << res[i];
    else
        cout << 1;
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}