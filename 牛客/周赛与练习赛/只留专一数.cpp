#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2000;
vector<int> vis(N + 1), p;
void init()
{
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            p.pb(i);
        }
        for (int j = 0; p[j] < N / i; j++)
        {
            vis[p[j] * i] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int x;
    bool ok = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int cnt = 0;
        for (int j = 0; j < p.size() && x >= p[j]; j++)
        {
            if (x % p[j] == 0)
                cnt++;
        }
        if (cnt == 1 || x == 1)
            ok = 1;
    }
    cout << (ok ? "YES\n" : "NO\n");
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}