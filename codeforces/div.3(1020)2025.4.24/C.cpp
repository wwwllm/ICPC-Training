#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    int ma = -1, sum = -1, mi = INF;
    bool flag = 1;
    for (auto &x : a)
        cin >> x, ma = max(ma, x), mi = min(mi, x);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] != -1 && sum == -1)
            sum = b[i] + a[i];
        else if (b[i] != -1 && sum != -1)
        {
            if (b[i] + a[i] != sum)
                flag = 0;
        }
    }
    if (!flag)
        cout << 0 << endl;
    else
    {
        if (sum != -1)
        {
            if (ma > sum || sum - mi > k)
                cout << 0 << endl;
            else cout << 1 << endl;
        }
        else
            cout << k - (ma - mi) + 1 << endl;
    }
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