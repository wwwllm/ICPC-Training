#include <bits/stdc++.h>
#define int long long
using namespace std;

struct ST
{
#define lg2(n) (63 - __builtin_clzll((int)(n)))
    int n;
    vector<vector<int>> st;
    ST(int n, vector<int> &a) : n(n)
    {
        int bit = lg2(n) + 2;
        st.assign(bit, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            st[0][i] = a[i];

        for (int j = 1; j < bit; j++)
        {
            for (int i = 0; i + (1ll << j) - 1ll < n; i++)
            {
                st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1ll << (j - 1))]);
            }
        }
    }

    int query(int l, int r)
    {
        int k = lg2(r - l + 1);
        return gcd(st[k][l], st[k][r - (1ll << k) + 1]);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), d(n - 1);
    for (auto &X : a)
        cin >> X;
    bool ok = 0;
    for (int i = 1; i < n; i++)
    {
        d[i - 1] = abs(a[i] - a[i - 1]);
        if (d[i - 1])
            ok = 1;
    }
    if (!ok)
    {
        cout << 0 << '\n';
        return;
    }
    vector<int> pos;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = gcd(cur, a[i]);
        if (tmp != cur)
        {
            pos.push_back(i);
        }
        cur = tmp;
    }

    ST st2(n - 1, d), st1(n, a);
    int ans = st1.query(0, n - 1);
    for (int r = 0; r < n; r++)
    {
        int x = 0;
        if (r != n - 1)
        {
            x = st1.query(r + 1, n - 1);
        }

        for (int i = 0; i < pos.size(); i++)
        {
            if (pos[i] > r)
                continue;
            int y = 0;
            if (pos[i] != 0)
            {
                y = st1.query(0, pos[i] - 1);
            }
            int z = 0;
            if (r != 0 && pos[i] <= r - 1)
                z = st2.query(pos[i], r - 1);
            int tmp = gcd(x, gcd(y, z));
            ans = max(tmp, ans);
        }
        int y = 0;
        if (r != 0)
        {
            y = st1.query(0, r - 1);
        }
        int tmp = gcd(x, y);
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
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