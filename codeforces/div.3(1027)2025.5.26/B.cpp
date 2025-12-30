#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (auto it : s)
    {
        int u = it - '0';
        if (u == 1)
            cnt1++;
        else
            cnt0++;
    }
    cnt0 /= 2;
    cnt1 /= 2;
    if (abs(cnt0 - cnt1) > k || (cnt0 + cnt1 )< k || ((abs(cnt0 - cnt1) ^ k) & 1))
        cout << "NO\n";
    else
        cout << "YES\n";
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