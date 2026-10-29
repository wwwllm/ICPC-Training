#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> c(n);
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += abs(a[i] - a[i + 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        c[i] = abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]);
    }
    int d = 0;
    for (int b = 0; b < 16; b++)
    {
        array<int, 4> k{0};
        for (int i = 0; i < 4; i++)
        {
            k[i] = (((b >> i) & 1) ? -1 : 1);
        }
        vector<int> L(n + 1, -inf);
        for (int i = 1; i < n - 1; i++)
        {
            L[i] = k[0] * a[i - 1] + k[1] * a[i + 1] - (k[2] + k[3]) * a[i] - c[i];
            L[i] = max(L[i - 1], L[i]);
        }
        for (int i = 3; i < n - 1; i++)
        {
            int r = k[2] * a[i - 1] + k[3] * a[i + 1] - (k[0] + k[1]) * a[i] - c[i];
            int l = L[i - 2];
            d = max(r + l, d);
        }
    }
    auto calc = [&](int x, int y)
    {
        vector<int> pos = {x - 1, x, y, y - 1};
        ranges::sort(pos);
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        int ans1 = 0, ans2 = 0;
        for (auto i : pos)
        {
            if (i < 0 || i >= n - 1)
                continue;
            ans1 += abs(a[i] - a[i + 1]);
        }
        swap(a[x], a[y]);
        for (auto i : pos)
        {
            if (i < 0 || i >= n - 1)
                continue;
            ans2 += abs(a[i] - a[i + 1]);
        }
        swap(a[x], a[y]);
        return ans2 - ans1;
    };
    for (int i = 0; i < n; i++)
    {
        d = max(calc(i, 0), d);
        d = max(calc(i, n - 1), d);
        if (i + 1 < n)
            d = max(calc(i, i + 1), d);
    }
    cout << sum + d << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}