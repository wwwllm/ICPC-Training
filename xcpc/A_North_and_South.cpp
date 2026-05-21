#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0)
    {
        cout << -1 << '\n';
        return;
    }
    a[0] = sum / n;
    a[n + 1] = ((n + 1) & 1) ? -sum / n : sum / n;
    for (int i = 1; i <= n; i += 2)
    {
        a[i] = -a[i];
    }
    vector<int> d(n + 2);
    for (int i = 1; i <= n + 1; i++)
    {
        d[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= n + 1; i += 2)
    {
        d[i] = -d[i];
    }
    int odd1 = 0, even1 = 0; //--
    int odd2 = 0, even2 = 0; //++
    int tag = 2 * sum / n;

    for (int i = n + 1; i >= 1; i--)
    {
        if (i & 1)
        {
            if (d[i] > tag)
            {
                odd1 += d[i] - tag;
            }
            else
            {
                odd2 += tag - d[i];
                if (odd2 > odd1)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        else
        {
            if (d[i] > tag)
            {
                even1 += d[i] - tag;
            }
            else
            {
                even2 += tag - d[i];
                if (even2 > even1)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    int odd = odd1 + odd2, even = even1 + even2;
    if ((even & 1) || (odd & 1))
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << odd / 2 + even / 2 << '\n';
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