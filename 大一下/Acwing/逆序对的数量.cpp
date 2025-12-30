#include <bits/stdc++.h>
#define int long long
#define MAXN 100050
using namespace std;

int n;
int t[MAXN], a[MAXN], ans = 0;
void solve(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    solve(l, mid), solve(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (t[i] <= t[j])
            a[k++] = t[i++];
        else
            a[k++] = t[j++], ans += mid - i + 1;
    }
    while (i <= mid)
        a[k++] = t[i++];
    while (j <= r)
        a[k++] = t[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        t[i] = a[j];
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    solve(1, n);
    cout << ans << endl;
    return 0;
}
