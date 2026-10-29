#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<int> aa;
    for (auto it : a)
    {
        int op;
        cin >> op;
        if (op)
            aa.push_back(it);
    }
    bool ok = 1;
    for (int i = 0, j = 0; i < aa.size(); i++)
    {
        while (j < n && b[j] != aa[i])
            j++;
        if (j == n && b[j - 1] != aa[i])
        {
            ok = 0;
            break;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
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