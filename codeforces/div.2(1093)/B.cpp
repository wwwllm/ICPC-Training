#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int len = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0, j; i < n; i++)
    {
        j = i;
        while (j < n && a[i] == a[j])
            j++;
        len = max(j - i, len);
        i = j - 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[0])
        {
            cnt++;
            break;
        }
    }
    if (len < m && cnt <= (m - a[0]))
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