#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2066/A
int query(int i, int j)
{
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    set<int> S;
    for (int i = 1; i <= n; i++)
        S.insert(i);
    for (auto it : a)
    {
        if (S.count(it))
            S.erase(it);
    }
    if (S.size())
    {
        for (auto it : S)
        {
            int x;
            if (it == n)
                x = query(it, it - 1);
            else
                x = query(it, it + 1);
            if (x == 0)
            {
                cout << "! A\n";
                cout.flush();
            }
            else
            {
                cout << "! B\n";
                cout.flush();
            }
            break;
        }
    }
    else
    {
        int p1, p2;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                p1 = i + 1;
            if (a[i] == n)
                p2 = i + 1;
        }
        int x1 = query(p1, p2);
        int x2 = query(p2, p1);
        if (x1 == x2 && x1 + x2 >= 2 * (n - 1))
        {
            cout << "! B\n";
            cout.flush();
        }
        else
        {
            cout << "! A\n";
            cout.flush();
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