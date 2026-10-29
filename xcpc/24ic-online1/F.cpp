#include <bits/stdc++.h>
#define int long long
using namespace std;

struct CartesianTree
{
    int n, root;
    vector<int> lc, rc, fa;

    CartesianTree() : n(0), root(-1) {}

    template <class T, class Compare = less<T>>
    CartesianTree(const vector<T> &a, Compare comp = Compare())
    {
        init(a, comp);
    }

    template <class T, class Compare = less<T>>
    void init(const vector<T> &a, Compare comp = Compare())
    {
        n = a.size();
        root = -1;
        lc.assign(n, -1);
        rc.assign(n, -1);
        fa.assign(n, -1);

        vector<int> stk;
        stk.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int last = -1;
            while (!stk.empty() && comp(a[i], a[stk.back()]))
            {
                last = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
            {
                rc[stk.back()] = i;
                fa[i] = stk.back();
            }
            if (last != -1)
            {
                lc[i] = last;
                fa[last] = i;
            }
            stk.push_back(i);
        }
        if (!stk.empty())
            root = stk.front();
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    CartesianTree t(a, greater<int>());
    map<int, int> mp;
    int ans = 0;
    auto dfs = [&](auto &&self, int u, int cnt, map<int, int> &mp) -> void
    {
        ans += cnt;
        if (t.lc[u] != -1)
        {
            int ls = t.lc[u];
            mp[a[ls]]++;
            if (mp[a[ls]] == 1)
                cnt++;
            self(self, ls, cnt, mp);
            mp[a[ls]]--;
            if (mp[a[ls]] == 0)
                cnt--;
        }
        if (t.rc[u] != -1)
        {
            int rs = t.rc[u];
            mp[a[rs]]++;
            if (mp[a[rs]] == 1)
                cnt++;
            self(self, rs, cnt, mp);
            mp[a[rs]]--;
            if (mp[a[rs]] == 0)
                cnt--;
        }
    };
    mp[a[t.root]]++;
    dfs(dfs, t.root, 0, mp);
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