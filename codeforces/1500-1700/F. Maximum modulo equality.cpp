#include <bits/stdc++.h>
using namespace std;

struct ST
{
#define lg2(n) (63 - __builtin_clzll(n))
    int n;
    vector<vector<int>> st;
    ST(int n, vector<int> &a)
    {
        int layers = lg2(n) + 2;
        st.assign(layers, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];
        for (int j = 1; j < layers; j++)
        {
            for (int i = 0; i + (1LL << j) - 1LL < n; i++)
            {
                st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1LL << (j - 1))]);
            }
        }
    }
    int query(int l, int r)
    {
        int k = lg2(r - l + 1);
        return gcd(st[k][l], st[k][r - (1LL << k) + 1]);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        d[i] = abs(a[i] - a[i - 1]);
    ST st(n, d);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << 0 << ' ';
            continue;
        }
        int res = st.query(l, r - 1);
        cout << res << ' ';
    }
    cout << '\n';
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