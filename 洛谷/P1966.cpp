#include <bits/stdc++.h>
#define int long long
using namespace std;

//(a-b)^2=a^2+b^2-2ab
// ∑a[i]*b[i]最大，排序不等式,a中第i大的和b中第i大的相乘
// 通过归并求逆序对
const int mod = 1e8 - 3, maxn = 1e5 + 50;
struct N
{
    int n, pos;
} l1[maxn], l2[maxn];
bool cmp(N a, N b)
{
    return a.n < b.n;
}
int a[maxn], t[maxn], ans = 0;
void f(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    f(l, mid), f(mid + 1, r);
    for (int i = l, j = l, k = mid + 1; i <= r; i++)
    {
        if (j == mid + 1) // 左半边都排完了
            t[i] = a[k++];
        else if (k == r + 1)
        { // 右半边都排完了
            t[i] = a[j++];
            ans = (ans + k - mid - 1) % mod;
        }
        else if (a[j] <= a[k])
        {
            t[i] = a[j++];
            ans = (ans + k - mid - 1) % mod; // 产生逆序对
        }
        else
            t[i] = a[k++];
    }
    for (int i = l; i <= r; i++)
        a[i] = t[i];
}
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l1[i].n, l1[i].pos = i;
    for (int i = 1; i <= n; i++)
        cin >> l2[i].n, l2[i].pos = i;
    sort(l1 + 1, l1 + 1 + n, cmp);
    sort(l2 + 1, l2 + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        a[l2[i].pos] = l1[i].pos;
    f(1, n);
    cout << ans << endl;
    return 0;
}