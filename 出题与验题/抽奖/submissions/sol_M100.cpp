#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 100, N = 1e5;
using i128 = __int128;
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
    auto check = [&](int x, int l, int r, int p, int q) -> bool
    {
        if (pos.find(x) == pos.end())
            return 0;
        int cnt = ranges::upper_bound(pos[x], r) - ranges::lower_bound(pos[x], l);
        if (cnt * q > (r - l + 1) * p)
            return 1;
        else
            return 0;
    };
    while (Q--)
    {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        l--, r--;
        int ans = -1;
        for (int i = 0; i < M; i++)
        {
            int pos = randINT(l, r);
            if (check(a[pos], l, r, p, q))
            {
                ans = a[pos];
                break;
            }
        }
        cout << ans << '\n';
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
