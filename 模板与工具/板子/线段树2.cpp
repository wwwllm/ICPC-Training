#include <bits/stdc++.h>
#define int long long
using namespace std;

// 线段树同时时间区间重置和区间修改以及区间查询
const int N = 1e6 + 10,INF=0x3f3f3f3f3f3f3f;
int maxn[N << 2], n, a[N], ad[N << 2], m, change[N << 2];
bool update[N << 2];
void addlazy(int idx, int v)
{
    maxn[idx] += v;
    ad[idx] += v;
}
void updatelazy(int idx, int v)
{
    maxn[idx] = v;
    ad[idx] = 0;
    update[idx] = 1;
    change[idx] = v;
}
void down(int idx)
{
    if (update[idx])
    {
        updatelazy(idx << 1, change[idx]);
        updatelazy(idx << 1 | 1, change[idx]);
        update[idx] = 0;
    }
    if (ad[idx])
    {
        addlazy(idx << 1, ad[idx]);
        addlazy(idx << 1 | 1, ad[idx]);
        ad[idx] = 0;
    }
}
void up(int idx)
{
    maxn[idx] = max(maxn[idx << 1] , maxn[idx << 1 | 1]);
};
void build(int l, int r, int idx) // O(n)
{
    if (l == r)
    {
        maxn[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1), build(mid + 1, r, idx << 1 | 1);
    up(idx);
    ad[idx] = 0, update[idx] = 0;
}
int query(int x, int y, int l, int r, int idx) // O(logn)
{
    if (x <= l && y >= r)
        return maxn[idx];
    int ans = -INF;
    int mid = (l + r) >> 1;
    down(idx);
    if (x <= mid)
        ans =max(ans, query(x, y, l, mid, idx << 1));
    if (y > mid)
        ans = max(ans,query(x, y, mid + 1, r, idx << 1 | 1));
    return ans;
}
void add(int x, int y, int v, int l, int r, int idx)
{
    if (x <= l && y >= r)
        addlazy(idx, v);
    else
    {
        int mid = l + r >> 1;
        down(idx);
        if (x <= mid)
            add(x, y, v, l, mid, idx << 1);
        if (y > mid)
            add(x, y, v, mid + 1, r, idx << 1 | 1);
        up(idx);
    }
}
void to_change(int x, int y, int v, int l, int r, int idx)
{
    if (x <= l && y >= r)
        updatelazy(idx, v);
    else
    {
        int mid = l + r >> 1;
        down(idx);
        if (x <= mid)
            to_change(x, y, v, l, mid, idx << 1);
        if (y > mid)
            to_change(x, y, v, mid + 1, r, idx << 1 | 1);
        up(idx);
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            int x, y, z;
            cin >> x >> y >> z;
            add(x, y, z, 1, n, 1);
        }
        else if (op == 3)
        {
            int x, y;
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << endl;
        }else{
            int x, y, z;
            cin >> x >> y >> z;
            to_change(x, y, z, 1, n, 1);
        }
    }
    return 0;
}