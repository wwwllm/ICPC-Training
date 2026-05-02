#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[(i + 1) % n])
            cnt++;
        if (s[i] == s[(i + 1) % n])
            len = 1;
    }
    if (len == 1)
        cnt++;
    cout << cnt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}