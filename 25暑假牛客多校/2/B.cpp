#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n > 60)
    {
        cout << "NO\n";
    }
    else
    {
        bool ok = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int z = a[i] ^ a[j];
                if (max(a[i], a[j]) >= z)
                    ok = 1;
            }
        if (ok)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
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