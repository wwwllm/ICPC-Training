#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 31; i >= 0; i--)
    {
        if ((n >> i & 1) == 0)
        {
            int j = i;
            while (j >= 0 && (n >> j & 1) == 0)
                j--;
            if (i - j == 1)
            {
                ans.push_back(0);
            }
            else
            {
                if ((n >> j & 1) == 0 || j == -1)
                {
                    cout << "NO\n";
                    return;
                }
                ans.push_back(1);
                for (int k = i - 1; k >= j; k--)
                    ans.push_back(-1);
                i = j;
            }
        }
        else
        {
            ans.push_back(1);
        }
    }
    ranges::reverse(ans);
    cout << "YES\n";
    for (int i = 0; i <= 31; i++)
    {
        cout << ans[i] << " \n"[i % 8 == 7];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}