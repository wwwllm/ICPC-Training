#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    s += s;
    s = ';' + s;
    vector<int> len;
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            p = i;
            break;
        }
    }
    if (s[n] == '1' && p > 1)
        len.push_back(p - 1);
    for (int i = p; i <= n; i++)
    {
        if (s[i] == '0')
        {
            int j = i;
            while (j < s.size() && s[j] == '0')
                j++;
            len.push_back(j - i);
            i = j;
        }
    }
    if (len.empty())
    {
        cout << 0 << '\n';
        return;
    }
    sort(len.begin(), len.end());
    int x = *len.rbegin();
    int ans = 0;
    ans += max(0LL, x - t - 1);
    for (int i = 0; i < len.size() - 1; i++)
    {
        ans += max(0LL, len[i] - 2 * t);
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