#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector g(n + 1, vector<int>(n + 1));
    vector<int> a(n + 1);
    int l = 0, r = n - 1;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            a[i] = r--;
        else
            a[i] = l++;
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> tmp;
        for (int j = 1; j <= n; j++)
        {
            if (a[i] > a[j])
                tmp.pb(1);
            else
                tmp.pb(0);
        }
        for (auto x : tmp)
            cout << x;
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}