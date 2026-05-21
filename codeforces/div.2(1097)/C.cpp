#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;
    vector<int> a(n + 1), b(n + 1);
    A = ' ' + A, B = ' ' + B;
    for (int i = 1; i <= n; i++)
    {
        a[i] = A[i] == '(' ? 1 : -1;
        b[i] = B[i] == '(' ? 1 : -1;
    }
    int prea = 0, preb = 0;
    bool ok = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
        {
            prea += a[i], preb += b[i];
            if (prea < 0 || preb < 0)
                ok = 1;
        }
        else
        {
            if (prea > preb)
            {
                a[i] = -1, b[i] = 1;
            }
            else
            {
                a[i] = 1, b[i] = -1;
            }
            prea += a[i], preb += b[i];
            if (prea < 0 || preb < 0)
                ok = 1;
        }
    }
    if (prea != 0 || preb != 0)
        ok = 1;
    cout << (!ok ? "YES\n" : "NO\n");
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