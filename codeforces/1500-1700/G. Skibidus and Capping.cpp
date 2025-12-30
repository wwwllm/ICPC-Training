#include <bits/stdc++.h>
#define int long long
using namespace std;

//  https://codeforces.com/problemset/problem/2065/G
const int N = 2e5 + 10;
vector<int> pri, prih, val(N + 1);
vector<int> q(N + 1);
void s()
{
    for (int i = 2; i <= N; i++)
    {
        if (!val[i])
        {
            pri.push_back(i);
            for (int j = 0; j < pri.size() && pri[j] <= N / i; j++)
            {
                val[pri[j] * i] = 2;
                q[pri[j] * i] = pri[j];
                if (i % pri[j] == 0)
                    break;
            }
        }
        else
            for (int j = 0; j < pri.size() && pri[j] <= N / i; j++)
            {
                val[pri[j] * i] = 1;
                if (i % pri[j] == 0)
                    break;
            }
    }
}
void solve()
{
    int n;
    cin >> n;
    int sum = 0, ans = 0;
    map<int, int> mpp, mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!val[x])
            mpp[x]++, sum++;
        else if (val[x] == 2)
            mp[x]++;
    }
    for (auto [p, cnt] : mpp)
    {
        sum -= cnt;
        ans += cnt * sum;
    }
    for (auto [p, cnt] : mp)
    {
        int u = q[p], v = p / q[p];
       // cout << p << ":" << mp[p] << "  " << u << ":" << mpp[u] << "  " << v << ":" << mpp[v] << '\n';
        if (u != v)
            ans += mp[p] * (mpp[u] + mpp[v]) + mp[p] * (mp[p] + 1) / 2;
        else
            ans += mp[p] * mpp[u] + mp[p] * (mp[p] + 1) / 2;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    s();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}