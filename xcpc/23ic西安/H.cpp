#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int m = 1LL << n;
    vector<int> a(m + 1);
    vector<int> pos(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i], pos[a[i]] = i;
    vector<int> ans(m + 1);
    for (int c = 1; c <= n; c++)
    {
        int len = (1LL << c);
        for (int i = 1; i <= m; i += len)
        {
            int mid = i + len / 2;
            int l = i, r = i + len;
            vector<int> tmp;
            int pl = l, pr = mid;
            while (pl != mid || pr != r)
            {
                if (pl == mid)
                    tmp.push_back(a[pr++]);
                else if (pr == r)
                    tmp.push_back(a[pl++]);
                if (pr != r && pl != mid)
                {
                    if (a[pl] < a[pr])
                        tmp.push_back(a[pl++]);
                    else
                        tmp.push_back(a[pr++]);
                }
            }
            for (int j = l; j < r; j++)
                a[j] = tmp[j - l];
            for (int j = l; j < r; j++)
            {
                int val = a[j];
                int cnt = r - j - 1;
                if (cnt <= k && a[j] >= len)
                {
                    ans[pos[a[j]]] = c;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " \n"[i == m];
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
