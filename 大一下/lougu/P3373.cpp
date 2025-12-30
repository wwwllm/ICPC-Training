#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int sum[N << 2], add[N << 2], a[N], m, n, q, mul[N << 2];
void up(int idx);
void build(int l, int r, int idx)
{
    if (l == r)
        sum[idx] = a[l] % m;
    else
    {
        int mid = l + r >> 1;
        build(l, mid, idx << 1), build(mid + 1, r, idx << 1 | 1);
        up(idx);
    }
    add[idx] = 0;
    mul[idx] = 1;
}
void addlazy(int idx, int v, int n)
{
    sum[idx] = (sum[idx] + v * n) % m;
    add[idx] = (add[idx] + v) % m;
}
void mullazy(int idx, int v)
{
    sum[idx] = sum[idx] * v % m;
    add[idx] = add[idx] * v % m;
    mul[idx] = mul[idx] * v % m;
}
void up(int idx)
{
    sum[idx] = (sum[idx << 1] + sum[idx << 1 | 1]) % m;
}
void down(int idx, int ln, int rn)
{
    sum[idx << 1] = (sum[idx << 1] * mul[idx] + add[idx] * ln) % m;
    sum[idx << 1 | 1] = (sum[idx << 1 | 1] * mul[idx] + add[idx] * rn) % m;

    mul[idx << 1] = mul[idx << 1] * mul[idx] % m;
    mul[idx << 1 | 1] = mul[idx << 1 | 1] * mul[idx] % m;

    add[idx << 1] = (add[idx << 1] * mul[idx] + add[idx]) % m;
    add[idx << 1 | 1] = (add[idx << 1 | 1] * mul[idx] + add[idx]) % m;

    add[idx] = 0, mul[idx] = 1;
}
int query(int x, int y, int l, int r, int idx)
{
    if (x <= l && y >= r)
        return sum[idx];
    int ans = 0, mid = l + r >> 1;
    down(idx, mid - l + 1, r - mid);
    if (x <= mid)
        ans = (ans + query(x, y, l, mid, idx << 1)) % m;
    if (y > mid)
        ans = (ans + query(x, y, mid + 1, r, idx << 1 | 1)) % m;
    return ans % m;
}
void ad(int x, int y, int v, int l, int r, int idx)
{
    if (x <= l && y >= r)
        addlazy(idx, v, r - l + 1);
    else
    {
        int mid = l + r >> 1;
        down(idx, mid - l + 1, r - mid);
        if (x <= mid)
            ad(x, y, v, l, mid, idx << 1);
        if (y > mid)
            ad(x, y, v, mid + 1, r, idx << 1 | 1);
        up(idx);
    }
}
void mu(int x, int y, int v, int l, int r, int idx)
{
    if (x <= l && y >= r)
        mullazy(idx, v);
    else
    {
        int mid = l + r >> 1;
        down(idx, mid - l + 1, r - mid);
        if (x <= mid)
            mu(x, y, v, l, mid, idx << 1);
        if (y > mid)
            mu(x, y, v, mid + 1, r, idx << 1 | 1);
        up(idx);
    }
}
signed main()
{
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            mu(x, y, k, 1, n, 1);
        }
        else if (op == 2)
        {
            int x, y, k;
            cin >> x >> y >> k;
            ad(x, y, k, 1, n, 1);
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