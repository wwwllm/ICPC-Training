#include <bits/stdc++.h>
#define int long long
using namespace std;

int randINT(int l, int r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}

void solve()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        pos[a[i]].push_back(i);
    }
    auto calc = [&](int l, int r, int p, int q) -> int
    {
        for (int i = 0; i < 300; i++)
        {
            int idx = randINT(l, r);
            int lpos = ranges::lower_bound(pos[a[idx]], l) - pos[a[idx]].begin(), rpos = ranges::upper_bound(pos[a[idx]], r) - pos[a[idx]].begin();
            if ((rpos - lpos) * q >= (r - l + 1) * p)
            {
                return a[idx];
            }
        }
        return -1;
    };
    while (Q--)
    {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int res = calc(l, r, p, q);
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