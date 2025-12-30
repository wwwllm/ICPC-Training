#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int nxt[N][26];
char s[N];
int d[N];
void solve()
{
    memset(nxt, 0x3f, sizeof(nxt));
    int n, k;
    cin >> n >> k;
    cin >> s + 1;
    int q;
    cin >> q;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < k; j++)
        {
            nxt[i][j] = s[i] - 'a' == j ? i : nxt[i + 1][j];
        }
    }
    d[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        int mx = 0;
        for (int j = 0; j < k; j++)
        {
            mx = max(mx, nxt[i + 1][j]);
        }
        if (mx > n)
            d[i] = 1;
        else
            d[i] = 1 + d[mx];
    }
    while (q--)
    {
        string str;
        cin >> str;
        int p = 0;
        for (auto it : str)
        {
            int u = it - 'a';
            p = nxt[p + 1][u];
            if (p > n)
                break;
        }
        if (p <= n)
        {
            cout << d[p] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin >> t;
    while (t--)
        solve();
    return 0;
}