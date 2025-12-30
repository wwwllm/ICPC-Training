#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    set<int> s;
    s.insert(a[0]);
    int ans = 0;
    for (int i = 1, j = 1; i < n; i++)
    {
        set<int> tmp;
        while (j < n && s.size())
        {
            if (s.find(a[j]) != s.end())
                s.erase(a[j]);
            tmp.insert(a[j]);
            j++;
        }
        if (s.empty())
            ans++, s = tmp, i = j - 1;
        else
            break;
    }
    cout << ans + 1 << '\n';
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