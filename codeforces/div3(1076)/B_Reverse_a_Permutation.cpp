#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int st = 0, ed = 0, tar = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] != n - i && tar == -1)
            st = i, tar = n - i;
        if (tar != -1 && p[i] == tar)
        {
            ed = i;
            break;
        }
    }
    reverse(p.begin() + st, p.begin() + ed + 1);
    for (int i = 0; i < n; i++)
        cout << p[i] << " \n"[i == n - 1];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}