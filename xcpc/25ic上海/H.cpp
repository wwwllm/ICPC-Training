#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> r;
    int sum = 0;
    for (auto [x, cnt] : mp)
    {
        int k = cnt / 2;
        if (k & 1)
            sum ^= x;
        cnt -= k * 2;
        if (cnt)
            r.push_back(x);
    }
    if (r.size() > 2 || (r.size() == 2 && ranges::count(r, sum) == 0) || (r.size() == 0 && sum != 0))
    {
        cout << "Bot\n";
    }
    else
    {
        cout << "Menji\n";
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