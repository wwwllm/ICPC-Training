#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int n, m;
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
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        cin >> n >> m;
        int top = 0,ll;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x;
                cin >> x;
                if (x != 0)
                    t[++top] = x;
                else {
                    ll = i;
                }
            }
        }
        solve(1, n * m - 1);
        if (m & 1)
        {
            if (!(ans & 1))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }else{
            if ((ans+n-ll+1) & 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}