#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2013/C
void solve()
{
    int n;
    cin >> n;
    string s = "";
    int op;
    while (s.size() < n)
    {
        char x = '0';
        cout << "? " << s + x << endl;
        cin >> op;
        if (op == 0)
        {
            x = '1';
            cout << "? " << s + x << endl;
            cin >> op;
            if (op == 0)
                break;
            else
                s += x;
        }
        else
            s += x;
    }
    while (s.size() < n)
    {
        cout << "? " << '0' + s << endl;
        cin >> op;
        if (op)
            s = '0' + s;
        else
            s = '1' + s;
    }
    cout << "! " << s << endl;
    cout.flush();
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