#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n), b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());
    b = a;
    for (int i = 1, p = 0; i < n; i++)
    {
        if (i == n - 1 || a[i][0] - a[i - 1][0] <= a[i + 1][0] - a[i][0])
        {
            if (p == i)
            {
                b[i][0] = b[i - 1][0];
                p++;
                continue;
            }
            int pos = (a[i][0] + a[i - 1][0]) / 2;
            for (; p <= i; p++)
                b[p][0] = pos;
        }
    }
    vector<int> ans(n);
    for (auto [x, p] : b)
        ans[p] = x;
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
    return 0;
}