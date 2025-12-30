#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &ele : a)
        cin >> ele;
    
    int l = 0, r = n - 1;
    for (; l < n; l++)
    {
        if (a[l] == 1)
            break;
    }
    for (; r >= 0; r--)
        if (a[r] == 1)
            break;
    if (r - l + 1 > x)
        cout << "NO\n";
    else
        cout << "YES\n";
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