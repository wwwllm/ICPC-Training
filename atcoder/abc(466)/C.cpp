#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    auto query = [&](int x, int y)
    {
        cout << "? " << x << ' ' << y << endl;
        string s;
        cin >> s;
        return s == "Yes";
    };
    auto answer = [&](int ans)
    {
        cout << "! " << ans << endl;
    };
    int ans = 0;
    for (int i = 1, j = 2; i <= n; i++)
    {
        j = max(i + 1, j);
        while (j <= n && query(i, j))
        {
            j++;
        }
        ans += j - i - 1;
    }
    answer(ans);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}