#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 50;
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
            ans += k - mid - 1;
        }
        else if (a[j] <= a[k])
        {
            t[i] = a[j++];
            ans += k - mid - 1; // 产生逆序对
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
        cin >> a[i];
    f(1, n);
    cout << ans << endl;
    return 0;
}