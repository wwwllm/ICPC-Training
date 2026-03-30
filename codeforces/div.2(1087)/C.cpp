#include <bits/stdc++.h>
#define int long long
using namespace std;

// 0101

void solve()
{
    int n;
    cin >> n;
    auto answer = [&](int x)
    {
        cout << "! " << x << endl;
    };
    auto query = [&](int i, int j)
    {
        cout << "? " << i << " " << j << endl;
        int res;
        cin >> res;
        return res;
    };
    for (int i = 1; i < n; i++)
    {
        int x = 2 * i - 1, y = 2 * i;
        int res = query(x, y);
        if (res)
        {
            answer(x);
            return;
        }
    }
    int res = query(1, 2 * n);
    if (res)
    {
        answer(1);
        return;
    }
    res = query(2, 2 * n);
    if (res)
    {
        answer(2);
        return;
    }
    answer(2 * n - 1);
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