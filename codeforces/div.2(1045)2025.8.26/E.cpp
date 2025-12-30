#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 3);
    auto query = [&](int x) -> int
    {
        cout << "throw  " << x << endl;
        int cnt;
        cin >> cnt;
        return cnt;
    };
    auto Swap = [&](int x)
    {
        cout << "swap " << x << endl;
    };

    for (int i = n; i >= 1; i--)
    {
        if (dp[i + 1] == dp[i + 2])
            dp[i] = dp[i + 1] + 1;
        else
        {
            dp[i] = query(i);
            if (dp[i] == dp[i + 1] + 1)
                a[i] = 1;
            else
                a[i] = 2;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            Swap(i);
            int res = query(i + 1);
            if (res == dp[i + 2] + 1)
                a[i] = 1;
            else
                a[i] = 2;
        }
    }
    Swap(n - 1);
    int res = query(n - 1);
    if (res == 2)
        a[n] = 1;
    else
        a[n] = 2;
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << a[i];
    cout << '\n';
    cout.flush();
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