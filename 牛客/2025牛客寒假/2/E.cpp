#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 0x3f3f3f3f3f3f;
struct se_tree
{
    vector<ll> mx;
    int len;
    void up(int idx)
    {
        mx[idx] = max(mx[idx << 1], mx[idx << 1 | 1]);
    }
    void build(int idx, int l, int r, vector<ll> &a)
    {
        if (l == r)
        {
            mx[idx] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(idx << 1, l, mid, a), build(idx << 1 | 1, mid + 1, r, a);
        up(idx);
    }
    se_tree(vector<ll> &a, int n)
    {
        len = n << 2;
        mx.assign(len + 1, -INF);
        build(1, 1, n, a);
    }
    ll query(int x, int y, int l, int r, int idx)
    {
        if (x <= l && y >= r)
            return mx[idx];
        ll ans = -INF;
        int mid = l + r >> 1;
        if (x <= mid)
            ans = max(query(x, y, l, mid, idx << 1), ans);
        if (y > mid)
            ans = max(query(x, y, mid + 1, r, idx << 1 | 1), ans);
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), f(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        f[i] = a[i] - pre[i - 1];
    se_tree T(f, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // cout << T.query(l, r, 1, n, 1) << '\n';
        ll ans = max(0LL, pre[l] + T.query(l + 1, r, 1, n, 1) - a[l]);
        cout << ans << '\n';
    }
    return 0;
}