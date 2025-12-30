#include <bits/stdc++.h>
#define int long long
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
    int pos = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == b[i])
            pos = i;
    vector<int> aa, bb;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            bb.push_back(a[i]), aa.push_back(b[i]);
        else
            bb.push_back(b[i]), aa.push_back(a[i]);
    }
    cout << pos << '\n';
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