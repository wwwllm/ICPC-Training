#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[100];
void solve()
{
    int m, s, maxx = 0;
    cin >> m >> s;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        maxx = max(x, maxx);
        f[x] = 1;
    }
    int i = 1, cnt = m;
    while (s > 0 && i <= 100)
    {
        if (f[i])
            i++;
        else
        {
            s -= i;
            f[i] = 1;
            cnt++;
            i++;
        }
    }
    if (s == 0 && cnt >= maxx)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
