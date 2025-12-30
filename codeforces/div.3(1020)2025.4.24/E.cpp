#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int cnt = n - x;
        int p = pos[x];
        int n1 = 0, n0 = 0;
        int t1 = 0, t0 = 0;
        if (p > r || l > p)
            cout << -1 << ' ';
        else
        {
            while (l < r)
            {
                int mid = l + r >> 1;
                if (mid < p)
                {
                    l = mid + 1;
                    n0++;
                    if(a[mid]>x){
                        t0++;
                    }
                }
                else if (mid > p)
                {
                    r = mid - 1;
                    n1++;
                    if(a[mid]<x)
                        t1++;
                }
                else
                    break;
            }
            if (n1 > cnt || n0 > x - 1)
                cout << -1 << ' ';
            else
                cout << 2 * max(t1, t0) << ' ';
        }
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}