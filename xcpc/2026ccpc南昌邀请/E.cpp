#include <bits/stdc++.h>
#define int long long
using namespace std;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin >> n;
    vector<int> vis;
    auto answer = [&](int x)
    {
        cout << "! " << x << endl;
    };
    auto query = [&]() -> int
    {
        cout << "? " << vis.size() << ' ';
        for (auto x : vis)
            cout << x << ' ';
        cout << endl;
        int res = 0;
        cin >> res;
        return res;
    };
    set<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.insert(i);
    }
    int cnt = 1;
    bool ok = 0;
    while (cnt < 17)
    {
        for (int i = 1; i <= n; i++)
        {
            if (rng() % 2)
                vis.push_back(i);
        }
        if (vis.empty())
            continue;
        ok = 1;
        cnt++;
        int res = query();
        vis.clear();
        if (res == 0)
            continue;
        set<int> tmp;
        for (int j = 1; j <= res / j; j++)
        {
            if (res % j == 0)
            {
                int s = j + res / j;
                if (s <= n && ans.count(s))
                    tmp.insert(s);
            }
        }
        ans = tmp;
        if (ans.size() == 1)
            break;
    }
    if (ok)
        answer(*ans.begin());
    else
        answer(1);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}