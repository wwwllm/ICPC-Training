#include <bits/stdc++.h>
#define int long long
using namespace std;

int lowbit(int x)
{
    return x & -x;
}
struct BIT
{
    vector<int> tr;
    int n;
    BIT(int n) : n(n)
    {
        tr.assign(n + 1, 0);
    }
    void add(int pos, int v)
    {
        for (int i = pos; i <= n; i += lowbit(i))
            tr[i] += v;
    }
    int query(int x)
    {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i))
            ans += tr[i];
        return ans;
    }
};
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1), p, tmp;
    for (int i = 1; i <= n; i++)
        cin >> a[i], p.push_back(a[i]);
    tmp = a;
    vector<array<int, 2>> op(t);
    for (auto &[pos, v] : op)
    {
        cin >> pos >> v;
        p.push_back(tmp[pos] + v);
        tmp[pos] += v;
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    BIT tr(p.size());

    for (int i = 1; i <= n; i++)
    {
        int pa = lower_bound(p.begin(), p.end(), a[i]) - p.begin() + 1;
        tr.add(pa, 1);
    }

    for (auto [pos, v] : op)
    {
        int pa = lower_bound(p.begin(), p.end(), a[pos]) - p.begin() + 1;
        tr.add(pa, -1);
        a[pos] += v;
        pa = lower_bound(p.begin(), p.end(), a[pos]) - p.begin() + 1;
        tr.add(pa, 1);
        int l = -1, r = p.size();
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (tr.query(mid + 1) <= (n + 1) / 2)
            {
                l = mid;
            }
            else
                r = mid;
        }
        cout << tr.query(l + 1) << '\n';
    }
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