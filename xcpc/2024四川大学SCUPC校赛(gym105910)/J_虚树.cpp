#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
void solve()
{
    int n;
    cin >> n;
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ind[i];
    }
    if (n == 1)
    {
        if (ind[1] == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    vector<int> dp(n + 1);
    dp[n] = 1;
    if (ind[n] != 1)
    {
        cout << "No\n";
        return;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (i == 1)
        {
            dp[i] = ind[i] - dp[i + 1];
            continue;
        }
        if (dp[i + 1] == 0)
        {
            dp[i] = ind[i];
            if (dp[i] != 1)
            {
                cout << "No\n";
                return;
            }
        }
        else
        {
            int cnt = ind[i] - 1;
            if (dp[i + 1] >= cnt)
            {
                dp[i] = dp[i + 1] - cnt + 1;
            }
            else
            {
                int e = cnt + 1 - dp[i + 1];
                if (e != 1)
                {
                    cout << "No\n";
                    return;
                }
                dp[i] = 1;
            }
        }
    }
    if (dp[1] == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}