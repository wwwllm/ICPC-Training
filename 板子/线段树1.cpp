#include <bits/stdc++.h>
#define int long long
using namespace std;

// 可维护的信息：累加和，最大值。时间复杂度：O(1)
// 可实现的功能：范围查询，范围修改。时间复杂度:O(logn)
const int N = 1e5 + 10;
int sum[N << 2], n, a[N], ad[N << 2], m;
void lazy(int idx, int v, int n)
{
    sum[idx] += v * n;
    ad[idx] += v;
}
void down(int idx, int ln, int rn)
{
    if (ad[idx]!=0)
    {
        lazy(idx << 1, ad[idx], ln);
        lazy(idx << 1 | 1, ad[idx], rn);
        ad[idx] = 0;
    }
};
void up(int idx)
{
    sum[idx] = sum[idx << 1] + sum[idx << 1 | 1];
};
void build(int l, int r, int idx) // O(n)
{
    if (l == r)
    {
        sum[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1), build(mid + 1, r, idx << 1 | 1);
    up(idx);
}
int query(int x, int y, int l, int r, int idx) // O(logn)
{
    if (x <= l && y >= r)
        return sum[idx];
    int ans = 0;
    int mid = (l + r) >> 1;
    down(idx, mid - l + 1, r - mid);
    if (x <= mid)
        ans += query(x, y, l, mid, idx << 1);
    if (y > mid)
        ans += query(x, y, mid + 1, r, idx << 1 | 1);
    return ans;
}
void add(int x, int y, int v, int l, int r, int idx)
{
    if (x <= l && y >= r)
        lazy(idx, v, r - l + 1);
    else
    {
        int mid = l + r >> 1;
        down(idx, mid - l + 1, r - mid);
        if (x <= mid)
            add(x, y, v, l, mid, idx << 1);
        if (y > mid)
            add(x, y, v, mid + 1, r, idx << 1 | 1);
        up(idx);
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            add(x, y, z, 1, n, 1);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << endl;
        }
    }
    return 0;
}