#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    sort(g.begin(), g.end(), [&](vector<int> a, vector<int> b)
         { return a[0] > b[0]; });
    vector<array<int, 2>> a;
    for (int i = 0; i < n; i++)
    {
        for (auto it : g[i])
            a.push_back({i, it});
    }
    int m = a.size();
    auto cnt = [&]() -> int
    {
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (a[i][1] > a[j][1])
                    res++;
            }
        }
        return res;
    };
    int kk = cnt();
    if (kk < k)
    {
        cout << "No\n";
    }
    else if (kk == k)
    {
        cout << "Yes\n";
        for (auto [pos, x] : a)
            cout
                << x << ' ';
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j + 1 < m; j++)
            {
                if (a[j + 1][0] == a[j][0])
                    continue;
                if (kk > k && a[j][1] > a[j + 1][1])
                {
                    swap(a[j + 1], a[j]);
                    kk--;
                }
            }
        }
        if (kk == k)
        {
            cout << "Yes\n";
            for (auto [pos, x] : a)
                cout << x << ' ';
            cout << '\n';
        }
        else
            cout << "No\n";
    }
    return 0;
}