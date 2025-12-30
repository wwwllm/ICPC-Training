#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;
int h[maxn], w[maxn];
int n, k, maxl = 0;
bool cmp(int x)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (h[i] / x) * (w[i] / x);
    }
    return ans >= k;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i] >> w[i], maxl = max(maxl, max(h[i], w[i]));
    int l = 0, r = maxl + 1, mid;
    while (l + 1 != r)
    {
        mid = (l + r) >> 1;
        if (cmp(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}