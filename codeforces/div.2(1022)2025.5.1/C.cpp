#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n + 2, -INF);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b;
    for (int i = 0; i <= n + 1; i++)
    {
        if (i == 0 || a[i] != a[i - 1])
            b.push_back(a[i]);
    }
    int len = b.size();
    for (int i = 1; i < len - 1; i++)
    {
        if (b[i - 1] < b[i] && b[i] > b[i + 1])
            ans++;
    }
    cout << ans << endl;
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