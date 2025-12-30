#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    set<char> S;
    S.insert(s[0]);
    S.insert(s[n - 1]);
    for (int i = 1; i < n - 1; i++)
    {
        if (S.count(s[i]))
        {
            cout << "Yes\n";
            return;
        }
        else
            S.insert(s[i]);
    }
    cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}