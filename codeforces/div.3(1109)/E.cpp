#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            a[i] ^= 1;
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        array<int, 2> c = {0, 0};
        for (int i = l; i <= r;)
        {
            int j = i;
            while (j <= r && a[i] == a[j])
            {
                j++;
            }
            c[a[i]]++;
            i = j;
        }
        if (min(c[0], c[1]) <= k)
            cout << "YES\n";
        else
            cout << "NO\n";
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