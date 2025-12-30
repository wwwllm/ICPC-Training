#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2041/A
void solve()
{
    vector<int> st(6, 0);
    for (int i = 1; i <= 4; i++)
    {
        int x;
        cin >> x;
        st[x] = 1;
    }
    for (int i = 1; i <= 5; i++)
    {
        if (!st[i])
            cout << i << '\n';
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