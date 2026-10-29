#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << -1 << '\n';
    }
    else if (n == 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        vector<int> ans(n);
        ans[0] = 1, ans[1] = 2, ans[2] = 3;
        int sum = 6;
        for (int i = 3; i < n; i++)
        {
            ans[i] = sum;
            sum += ans[i];
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
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