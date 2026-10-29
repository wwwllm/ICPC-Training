#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "Bob\n";
        return;
    }
    vector<int> ind(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ind[u]++, ind[v]++;
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        c += (ind[i] > 1);
    }
    if (c & 1)
        cout << "Bob\n";
    else
        cout << "Alice\n";
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