#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] == n)
            l = r = i;
    }
    int idx = n;
    bool ok = 1;
    while (1)
    {
        if (p[l] != idx && p[r] != idx)
        {
            ok = 0;
            break;
        }
        if (l >= 1 && p[l] == idx)
        {
            l--;
        }
        if (r <= n && p[r] == idx)
        {
            r++;
        }
        idx--;
        if (idx == 0)
            break;
    }
    if (idx == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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