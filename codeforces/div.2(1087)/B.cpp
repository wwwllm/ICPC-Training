#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    for (int i = 0; i < n; i++)
    {
        int cmi = 0, cma = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
                cma++;
            else if (a[i] > a[j])
                cmi++;
        }
        cout << max(cmi, cma) << ' ';
    }
    cout << '\n';
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