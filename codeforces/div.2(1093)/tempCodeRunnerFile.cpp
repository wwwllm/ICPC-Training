#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    auto query = [&](vector<int> &a)
    {
        cout << "? " << a.size() << ' ';
        for (auto x : a)
            cout << x << ' ';
        cout << endl;
        int res = 0;
        cin >> res;
        return res;
    };
    vector<int> ans;
    int l = 0, r = 2 * n + 2;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        vector<int> a;
        for (int i = 1; i <= mid; i++)
            a.push_back(i);
        int res = query(a);
        if ((mid - res) & 1)
            r = mid;
        else
            l = mid;
    }
    ans.push_back(r);
    l = 0, r = 2 * n + 2;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        vector<int> a;
        for (int i = mid; i <= n * 2 + 1; i++)
            a.push_back(i);
        int res = query(a);
        if ((mid - res) & 1)
            l = mid;
        else
            r = mid;
    }
    ans.push_back(l);
    int l = min(ans[0], ans[1]), r = max(ans[0], ans[1]);
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        vector<int> a;
        for (int i = l + 1; i <= mid; i++)
            a.push_back(i);
        a.push_back(ans[0]), ans.push_back(ans[1]);
        int res = query(a);
        if ((mid - res) & 1)
            r = mid;
        else
            l = mid;
    }
    cout << "! " << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
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