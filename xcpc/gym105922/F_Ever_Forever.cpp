#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105922
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'e')
        {
            for (int j = i; j < n; j++)
            {
                if (s[j] == 'f')
                    ans += (j - i);
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}