#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 50;
int a[maxn], s[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || a[i] != a[i - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
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
