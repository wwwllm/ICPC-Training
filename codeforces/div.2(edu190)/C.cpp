#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0, c1 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            cnt1++;
        }
        else
        {
            ans += x;
            c1++;
            cnt0 += max(0LL, x / 2 - 1);
        }
    }
    if (c1 == 1)
    {
        cnt0++;
    }
    ans += min(cnt0, cnt1);
    cout << (ans < 3 ? 0 : ans) << '\n';
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