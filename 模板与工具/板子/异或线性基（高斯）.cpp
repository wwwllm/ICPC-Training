#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int row = 0;
    auto gauss = [&]()
    {
        for (int i = 60; i >= 0; i--)
        {
            for (int j = row; j < n; j++)
            {
                if ((a[j] >> i) & 1)
                {
                    swap(a[j], a[row]);
                    break;
                }
            }
            if (!((a[row] >> i) & 1))
                continue;
            for (int j = 0; j < n; j++)
            {
                if (j != row && (a[j] >> i) & 1)
                    a[j] ^= a[row];
            }
            row++;
            if (row == n)
                break;
        }
    };
    gauss();
    int ans = 0;
    for (int i = 0; i < row; i++)
        ans ^= a[i];
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}