#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 50;
int l[maxn], r[maxn], f[maxn], p[maxn];
int n, m, q;
bool check(int x)
{
    for (int i = 0; i <= n; i++)
        p[i] = 0;
    for (int i = 1; i <= x; i++)
        p[f[i]]++;
    for (int i = 1; i <= n; i++)
        p[i] += p[i - 1];
    for (int i = 1; i <= m; i++)
    {
        if (2 * (p[r[i]] - p[l[i] - 1]) > r[i] - l[i] + 1)
            return true;
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> f[i];
    int i = 0, j = q + 1, mid;
    while (i + 1 != j)
    {
        mid = (j + i) >> 1;
        if (check(mid))
            j = mid;
        else
            i = mid;
    }
    if (j == q + 1)
        cout << -1 << endl;
    else
        cout << j << endl;
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
