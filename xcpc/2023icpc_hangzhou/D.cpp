#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    a[2 * n] = 1;
    a[1] = 1 + 2 * (n - 2);
    for (int i = 2; i <= 2 * n - 1; i++)
    {
        if (i & 1)
            a[i] = -1;
        else
            a[i] = 2;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        cout << a[i] << " \n"[i == n * 2];
    }
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