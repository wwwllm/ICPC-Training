#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    array<int, 6> a;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> p;
    p.push_back(1);
    for (int i = 0; i < 6; i++)
    {
        p.push_back(a[i] + 1);
    }
    ranges::sort(p);
    p.erase(unique(p.begin(), p.end()), p.end());
    vector<int> path;
    vector<int> ans;
    auto check = [&]() -> bool
    {
        int c = 0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (path[i] > a[j])
                    c++;
            }
        }
        return c >= 19;
    };
    auto dfs = [&](auto &&self, int sum) -> bool
    {
        if (ans.size())
            return 1;
        if (path.size() == 5)
        {
            if (sum >= k)
                return 0;
            path.push_back(k - sum);
            if (check())
            {
                ans = path;
                return 1;
            }
            path.pop_back();
            return 0;
        }
        for (auto x : p)
        {
            if (x + sum <= k)
            {
                path.push_back(x);
                if (self(self, sum + x))
                    return 1;
                path.pop_back();
            }
        }
        return ans.size();
    };
    if (dfs(dfs, 0))
    {
        cout << "YES\n";
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}