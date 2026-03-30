#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> T(l + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        T[x] = 1;
    }
    vector<int> b(m);
    for (int i = 1; i <= l; i++)
    {
        ranges::sort(b, greater<int>());
        int k = min(n, m - 1);
        b[k]++;
        if (T[i])
        {
            n--;
            *ranges::max_element(b) = 0;
            ranges::sort(b, greater<int>());
        }
    }
    cout << *ranges::max_element(b) << '\n';
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