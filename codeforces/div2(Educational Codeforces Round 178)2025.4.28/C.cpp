#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnta = 0, cntb = 0;
    for (auto it : s)
    {
        if (it == 'A')
            cnta++;
        else
            cntb++;
    }
    if (s[0] == s[n - 1])
    {
        if (s[0] == 'A')
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    else
    {
        if (s[0] == 'B')
        {
            if (s[n - 2] == 'A')
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
        }
        else
        {
            if (cntb == 1)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
        }
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