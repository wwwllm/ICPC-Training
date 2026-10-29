#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a;
    cin >> n >> a;
    string s;
    cin >> s;
    int cnt = 0;
    int len1 = 0, len0 = 0;
    for (auto c : s)
    {
        if (c == '1')
            cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            int j = i;
            while (j < n && s[j] == '1')
                j++;
            len1 = max(len1, j - i);
            i = j - 1;
        }
        if (s[i] == '0')
        {
            int j = i;
            while (j < n && s[j] == '0')
                j++;
            len0 = max(len0, j - i);
            i = j - 1;
        }
    }

    if (len1 >= a || len0 >= a + 1)
    {
        cout << n << '\n';
    }
    else
        cout << cnt << '\n';
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