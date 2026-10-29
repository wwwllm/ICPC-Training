#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k < n || (n * n - k + 1) < n)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<int> st(n * n + 1);
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        g[i][i] = k + i;
        st[k + i] = 1;
    }
    for (int i = 1; i < n; i++)
        g[0][i] = k - i, st[k - i] = 1;
    int temp = n * n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 0)
            {
                while (st[temp])
                    temp--;
                g[i][j] = temp;
                st[temp] = 1;
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " \n"[j == n - 1];
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