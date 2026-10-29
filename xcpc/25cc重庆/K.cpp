#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] != 0)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i - 1] + 1)
        {
            cout << 0 << '\n';
            return;
        }
    }
    vector<int> root(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            root[i] = i;
        else
            root[i] = root[a[i]];
    }
    int ans = 1;
    vector<int> st;
    for (int i = 1, j = 0; i <= n; i++)
    {
        if (a[i] == 0)
            st.clear();
        while (j && root[i] != root[j + 1])
        {
            if (a[i] == 0)
                st.push_back(root[j + 1]);
            j = a[j];
        }
        if (a[i] == 0)
        {
            if (i != 1)
                st.push_back(1);
            ranges::sort(st);
            st.erase(unique(st.begin(), st.end()), st.end());
            int c = max(m - (int)st.size(), 0LL);
            (ans *= c) %= mod;
        }
        else
        {
            if (j + 1 != a[i])
                ans = 0;
            else
                j++;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}