#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2038/C
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> a;
    for (auto [x, cnt] : mp)
    {
        while (cnt >= 2)
        {
            a.push_back(x);
            cnt -= 2;
        }
    }
    if (a.size() < 4)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        sort(a.begin(), a.end());
        int len = a.size();
        array<int, 2> p1, p2;
        p1 = {a[0], a[1]};
        p2 = {a[len - 2], a[len - 1]};
        cout << p1[0] << ' ' << p1[1] << ' ' << p2[0] << ' ' << p2[1] << ' ' << p1[0] << ' ' << p2[1] << ' ' << p2[0] << ' ' << p1[1];
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}