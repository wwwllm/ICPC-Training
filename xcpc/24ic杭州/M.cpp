#include <bits/stdc++.h>
#define int long long
using namespace std;

struct CartesianTree
{
    int n, root;
    vector<int> lc, rc, fa;

    CartesianTree() : n(0), root(-1) {}

    template <class T, class Compare = less<T>>
    CartesianTree(const vector<T> &a, Compare cmp = Compare())
    {
        init(a, cmp);
    }

    template <class T, class Compare = less<T>>
    void init(const vector<T> &a, Compare cmp = Compare())
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
            while (!stk.empty() && cmp(a[i], a[stk.back()]))
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    CartesianTree t(a);
    vector<array<int, 2>> e;
    for (int i = 0; i < n; i++)
    {
        if (t.fa[i] != -1)
            e.push_back({a[t.fa[i]], a[i]});
    }
    unordered_set<int> ans;
    bool ok = 0;
    for (auto [u, v] : e)
    {
        if (u == v)
            continue;
        int d = v - u;
        if (!ok)
        {
            for (int i = 1; i <= d / i; i++)
            {
                if (d % i == 0)
                {
                    for (auto j : {i, d / i})
                    {
                        if (j > u)
                        {
                            int x = j - u;
                            if (x > k)
                                continue;
                            ans.insert(x);
                        }
                    }
                }
            }
            ok = 1;
            break;
        }
    }
    if (!ok)
    {
        cout << k << ' ' << k * (k + 1) / 2 << '\n';
        return;
    }
    int res = 0, cnt = 0;
    for (auto x : ans)
    {
        bool ok = 1;
        for (auto [u, v] : e)
        {
            if (u == v)
                continue;
            ok &= (v - u) % (u + x) == 0;
        }
        if (ok)
            res += x, cnt++;
    }

    cout << cnt << ' ' << res << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}