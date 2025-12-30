#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int v = 0, n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            v += 10;
            ans += v;
        }
        else if (s[i] == '1')
        {
            v = max(v - 5, (int)0);
            ans += v;
        }else{
            ans += max(v - 10, (int)0);
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t=1;
   // cin >> t;
    while (t--)
        solve();
    return 0;
}