#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int m = 1LL << n;
    vector<int> a(m);
    for (int i = 1; i < m; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    int cur = -1;
    vector<int> ans(m);
    for (int i = 1; i < m; i++)
    {
        if (a[i])
        {
            if (cur == -1)
            {
                cur = i;
            }
            else
            {
                ans[i] = cur;
                a[i] ^= 1;
                a[cur] ^= 1;
                a[cur ^ i] ^= 1;
                if ((cur ^ i) < i)
                    cur ^= i;
                else
                    cur = -1;
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        cout << ans[i] << " \n"[i == m - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}