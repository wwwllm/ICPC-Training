#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2052/A
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), tmp(n + 1);
    set<int> S;
    vector<array<int, 2>> res;
    for (auto &x : a)
        cin >> x, S.insert(x);
    int ans = 0;
    iota(tmp.begin() + 1, tmp.end(), 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int p;
        S.erase(a[i]);
        for (p = 1; p <= n; p++)
        {
            if (tmp[p] == a[i])
                break;
        }
        for (int j = p - 1; j >= 1; j--)
        {
            res.push_back({tmp[j + 1], tmp[j]});
            swap(tmp[j + 1], tmp[j]);
        }
        for (int i = 2; i <= n; i++)
        {
            if (S.count(tmp[i]))
            {
                res.push_back({tmp[i], tmp[i - 1]});
                swap(tmp[i], tmp[i - 1]);
            }
            else
                break;
        }
    }
    cout << res.size() << '\n';
    for (auto [x, y] : res)
        cout << x << ' ' << y << '\n';
    return 0;
}