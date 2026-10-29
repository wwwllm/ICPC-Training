#include <bits/stdc++.h>
using namespace std;

int b[26];
void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for (auto it : s)
    {
        int u = it - 'a';
        if (b[u] == 0)
        {
            if (it != 'i')
                ans++;
            b[u] = 1;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}