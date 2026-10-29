#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 50, INF = 1e9;
int a[maxn], ans = -INF;
void f(int l, int r)
{
    if (l == r)
    {
        ans = max(ans, a[l]);
    }
    else
    {
        int mid = (l + r) >> 1;
        f(l, mid), f(mid + 1, r);
        int lsum = -INF, rsum = -INF;
        for (int i = mid, sum = 0; i >= l; i--)
        {
            sum += a[i];
            lsum = max(sum, lsum);
        }
        for (int i = mid + 1, sum = 0; i <= r; i++)
        {
            sum += a[i];
            rsum = max(sum, rsum);
        }
        ans = max(ans, lsum + rsum);
    }
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