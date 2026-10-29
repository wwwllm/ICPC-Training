#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 55;
int w[maxn], t[2 * maxn], b[2 * maxn];
void solve()
{
    int n, ans = 0, num = 0;
    cin >> n;
    memset(t, 0, sizeof(t));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++)
        cin >> w[i], t[w[i]]++;
    for (int s = 1; s <= 2 * n; s++)
    {
        num = 0;
        for (int i = 1; i <= n; i++)
        {
            b[i] = t[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (w[i] >= s)
                continue;
            if (b[s-w[i]]>0 && s-w[i] != w[i] && b[w[i]]>0)
            {
                num++;
                b[s-w[i]]--;
                b[w[i]]--;
            }
            else if (b[s-w[i]] >= 2 && s-w[i] == w[i])
            {
                num++;
                b[s-w[i]] -= 2;
            }
        }
        ans = max(num, ans);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}