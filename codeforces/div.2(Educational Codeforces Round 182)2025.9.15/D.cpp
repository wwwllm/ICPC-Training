#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f;
void solve()
{
    int n, y;
    cin >> n >> y;
    vector<int> a(n), t(N), pre(N);
    for (auto &x : a)
        cin >> x;

    for (auto x : a)
        t[x]++;

    for (int i = 1; i < N; i++)
        pre[i] = pre[i - 1] + t[i];

    int ans = -INF;
    for (int i = 2; i < N; i++)
    {
        int sum = 0, cnt = 0;
        int p = 1;
        while (1)
        {
            int l = (p - 1) * i + 1;
            int r = min(p * i, N - 1);
            if (l > N)
                break;
            int res = pre[r] - pre[l - 1];
            if (res == 0)
            {
                p++;
                continue;
            }
            sum += res * p;
            int tmp = 0;

            if (p <= N)
                tmp = t[p];
            cnt += min(res, tmp);
            p++;
        }
        ans = max(ans, sum - y * (n - cnt));
    }
    cout << ans << "\n";
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