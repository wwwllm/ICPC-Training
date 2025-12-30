#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2003/C
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(26);
    for (auto it : s)
    {
        int u = it - 'a';
        a[u]++;
    }
    while (1)
    {
        bool ok = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] > 0)
                a[i]--, cout << char(i + 'a'), ok = 1;
        }
        if (!ok)
            break;
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