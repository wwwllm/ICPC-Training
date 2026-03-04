#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    set<int> s;
    s.insert(0);
    for (int i = 0; i < n; i++)
    {
        set<int> tmp;
        for (auto x : s)
        {
            tmp.insert(max(0LL, x - a[i]));
            tmp.insert(x ^ b[i]);
        }
        s = tmp;
    }
    cout << *s.rbegin() << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}