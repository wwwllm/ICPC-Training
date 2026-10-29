#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
vector<int> vis(N + 1), prime, cnt(N + 1);
void init()
{
    for (int i = 2; i <= N; i++)
    {
        if (vis[i] == 0)
            cnt[i] = 1, prime.push_back(i);
        for (auto j : prime)
        {
            if (j * i > N)
                break;
            vis[i * j] = 1;
            cnt[i * j] = cnt[i] + 1;
            if (i % j == 0)
                break;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (cnt[i] & 1)
            ans.push_back(i);
    if (ans.size() >= n / 2)
    {
        for (int i = 0; i < n / 2; i++)
            cout << ans[i] << " \n"[i == n / 2 - 1];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}