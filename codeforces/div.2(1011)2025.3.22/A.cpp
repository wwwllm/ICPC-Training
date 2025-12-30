#include <bits/stdc++.h>
using namespace std;

bool cmp(string s)
{
    int len = s.length();
    for (int i = 0, j = len - 1; i < len; i++, j--)
    {
        if (s[i] == s[j])
            continue;
        else
            return s[i] < s[j];
    }
    return 0;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
            flag = 1;
    }
    if((flag&&k>=1)||cmp(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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