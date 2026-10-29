#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
vector<int> sg = {0,
                  0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 0, 5, 2, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 2, 7, 4,
                  0, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 2, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4,
                  8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4,
                  8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4,
                  8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4,
                  8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0};
using u64 = unsigned long long;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// 获取一个随机的 64 位整数
u64 get_random()
{
    return rng();
}
void solve()
{
    // sg[1] = 0, sg[0] = 0;
    // auto SG = [&](auto &&self, int x) -> int
    // {
    //     if (sg[x] != -1)
    //         return sg[x];
    //     set<int> s;
    //     for (int l = 0; l <= x; l++)
    //     {
    //         int r = x - l - 2;
    //         if (r >= 0)
    //             s.insert(self(self, l) ^ self(self, r));
    //     }
    //     int mex = 0;
    //     while (s.count(mex))
    //     {
    //         mex++;
    //     }
    //     return sg[x] = mex;
    // };
    // for (int i = 0; i < n; i++)
    // {
    //     if (sg[i] == -1)
    //         SG(SG, i);
    //     cout << sg[i] << "," << " \n"[i % 34 == 0];
    // }
    auto SG = [&](int x)
    {
        if (x > 100)
            x = (x - 100) % 34 + 100;
        return sg[x];
    };
    vector<array<int, 2>> seg;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        seg.push_back({x, y});
    }
    vector<int> hash(m);
    for (int i = 0; i < m; i++)
    {
        hash[i] = get_random();
    }
    map<int, u64> mp;
    mp[n] = 0;
    for (int i = 0; i < m; i++)
    {
        auto [x, y] = seg[i];
        mp[x] ^= hash[i];
        mp[y] ^= hash[i];
    }
    u64 cur = 0;
    int pre = -1;
    map<u64, int> len;
    for (auto [x, H] : mp)
    {
        len[cur] += x - pre - 1;
        cur ^= H;
        pre = x;
    }
    int res = 0;
    for (auto [H, l] : len)
    {
        // cerr << l << '\n';
        res ^= SG(l);
    }
    cout << (res ? "YES\n" : "NO\n");
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}