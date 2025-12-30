#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p[N], d[N], ans[N];
bool b[N];
void solve()
{
    memset(b, 0, sizeof(b));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
    {
        if (b[d[i]])
            ans[i] = ans[i - 1];
        else
        {
            int res = 1;
            int pos = p[d[i]];
            b[pos] = 1;
            int flag = d[i];
            while (pos != flag)
            {
                pos = p[pos];
                if (!b[pos])
                    res++, b[pos] = 1;
            }
            ans[i] = ans[i - 1] + res;
        }
    }
    for (int i = 1; i <= n;i++)
        cout << ans[i] << ' ';
    cout << endl;
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