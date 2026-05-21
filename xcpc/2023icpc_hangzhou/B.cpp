#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> c[i];
    vector<int> r(0);
    r.push_back(0);
    while (r.back() < n)
    {
        r.push_back(1.5 * (r.back() + 1));
    }
    int cnt = r.size();
    bitset<N> st;
    vector col(n + 1, vector<int>());
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        st.set(x[i]), col[c[i]].push_back(i);
        pos[i] = ranges::upper_bound(r, i + 1) - r.begin() - 1;
    }
    vector<bitset<N>> ans(cnt + 1);
    for (int i = 0; i <= n; i++)
    {
        if (col[i].empty())
            continue;
        bitset<N> bit0;
        for (auto idx : col[i])
        {
            bit0.set(x[idx]);
        }
        auto bit1 = bit0 ^ st;
        for (auto idx : col[i])
        {
            ans[pos[idx]] |= (bit1 >> x[idx]);
        }
    }
    while (q--)
    {
        int k;
        cin >> k;
        int res = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (ans[i].test(k))
            {
                res = r[i];
                break;
            }
        }
        cout << res << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}