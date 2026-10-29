#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
vector<int> vis;
int n;
vector<int> alice(int pos);
vector<int> bob(int pos);
vector<int> calc(vector<int> &a)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            pos = i;
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(a[(i + pos) % n]);
    }
    return res;
}
vector<int> alice(int pos)
{
    if (pos == n)
    {
        return calc(a);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        a.push_back(i);
        auto tmp = bob(pos + 1);
        if (res.empty() || tmp < res)
        {
            res = tmp;
        }
        a.pop_back();
        vis[i] = 0;
    }
    return res;
}
vector<int> bob(int pos)
{
    if (pos == n)
    {
        return calc(a);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        a.push_back(i);
        auto tmp = alice(pos + 1);
        if (res.empty() || tmp > res)
        {
            res = tmp;
        }
        a.pop_back();
        vis[i] = 0;
    }
    return res;
}
void solve()
{
    cin >> n;
    a.clear();
    vis.assign(n + 1, 0);
    auto ans = alice(0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}