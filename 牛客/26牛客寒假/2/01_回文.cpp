#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto c : g[i])
            if (c == '0')
                cnt0++;
    }
    cnt1 = n * m - cnt0;
    if (cnt1 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (auto c : g[i])
            {
                if (c == '1')
                    cout << 'N';
                else
                    cout << "Y";
            }
            cout << '\n';
        }
    }
    else if (cnt0 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (auto c : g[i])
            {
                if (c == '0')
                    cout << 'N';
                else
                    cout << "Y";
            }
            cout << '\n';
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (auto c : g[i])
            {
                cout << "Y";
            }
            cout << '\n';
        }
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