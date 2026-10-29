#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector b(n + 1, vector<int>(n + 1));
    {
        for (int i = 0; i < n; i++)
        {
            priority_queue<int, vector<int>, greater<int>> r;
            priority_queue<int> l;
            for (int j = i; j < n; j++)
            {
                if (l.empty() || a[j] < l.top())
                    l.push(a[j]);
                else
                    r.push(a[j]);
                if (l.size() > r.size() + 1)
                {
                    r.push(l.top());
                    l.pop();
                }
                if (l.size() < r.size())
                {
                    l.push(r.top());
                    r.pop();
                }
                b[i][j] = l.top();
            }
        }
    }
    auto check = [&](int x) -> bool
    {
        vector pre(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                pre[i + 1][j + 1] =
                    pre[i][j + 1] + pre[i + 1][j] - pre[i][j];

                if (i <= j && b[i][j] < x)
                    pre[i + 1][j + 1]++;
            }
        }
        int cnt = 0;
        for (int l = 0; l < n; l++)
        {
            for (int r = l; r < n; r++)
            {
                int s = pre[r + 1][r + 1] - pre[l][r + 1] - pre[r + 1][l] + pre[l][l];
                int len = r - l + 1;
                int m = len * (len + 1) / 2;
                cnt += s >= (m + 1) / 2;
            }
        }

        return cnt < (n * (n + 1) / 2 + 1) / 2;
    };
    int l = 0, r = 1e9;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
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