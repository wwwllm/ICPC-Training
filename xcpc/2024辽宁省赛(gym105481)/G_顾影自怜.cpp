#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105481
const int inf = 1e18;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = a[n + 1] = inf;
    vector<int> stk;
    vector<int> l(n + 1), r(n + 1);
    stk.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && a[stk.back()] <= a[i])
        {
            stk.pop_back();
        }
        if (stk.size())
            l[i] = stk.back();
        else
            l[i] = 0;
        stk.push_back(i);
    }
    stk.clear();
    stk.push_back(n + 1);
    for (int i = n; i >= 1; i--)
    {
        while (stk.size() && a[stk.back()] <= a[i])
        {
            stk.pop_back();
        }
        if (stk.size())
            r[i] = stk.back();
        else
            r[i] = n + 1;
        stk.push_back(i);
    }
    vector<int> vis(n + 1), lst(n + 1), nxt(n + 1, n + 1);
    vector num(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        num[a[i]].push_back(i);
        if (num[a[i]].size() >= k)
        {
            nxt[num[a[i]][num[a[i]].size() - k]] = i;
        }
        lst[i] = vis[a[i]];
        vis[a[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int llen = i - max(lst[i], l[i]);
        int rlen = max(r[i] - nxt[i], 0LL);
        ans += llen * rlen;
    }
    cout << ans << '\n';
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