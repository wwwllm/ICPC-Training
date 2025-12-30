#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2072/E
void solve()
{
    int k;
    cin >> k;
    int x = 0, y = 0;
    vector<int> a(505);
    for (int i = 1; i <= 500; i++)
    {
        a[i] = (i - 1) * i / 2;
    }
    vector<array<int, 2>> ans;
    int j = 500;
    while (k)
    {
        if (a[j] <= k)
        {
            for (int i = 1; i <= j; i++)
            {
                ans.push_back({x, y});
                x++;
            }
            y++;
            k -= a[j];
        }
        else
            j--;
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
    {
        cout << x << ' ' << y << '\n';
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