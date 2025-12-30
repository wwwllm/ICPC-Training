#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--)
    {
        string t;
        int a;
        cin >> t >> a;
        int len = 0;
        int res = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[a + i - 1] == t[i])
                len++;
            else
                res += len * (len + 1) / 2, len = 0;
        }
        res += len * (len + 1) / 2;
        cout << res << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        solve();
    return 0;
}