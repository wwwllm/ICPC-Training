#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int c4 = 0;
    string ss;
    cin >> ss;
    string s = "";
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '4')
            c4++;
        else if (ss[i] != '0')
            s += ss[i];
    }
    if (s.empty())
    {
        cout << c4 << '\n';
        return;
    }
    int n = s.size();
    vector<int> pre(n), suf(n);
    pre[0] = (s[0] != '2');
    suf[n - 1] = (s[n - 1] == '2');
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + (s[i] != '2');
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + (s[i] == '2');
    }
    int ans = min(pre[n - 1], suf[0]) + c4;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, c4 + pre[i] + suf[i + 1]);
    }
    cout << ans << '\n';
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