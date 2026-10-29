// sol_AC.cpp —— 在你那份 sol_M100.cpp 的基础上做了 4 处改动，可以直接通过全部数据点
//
// 改动 1：采样次数 100 → 300
//         p/q >= 1/10 时合法答案被单次采样命中的概率 > 1/10，
//         100 次漏掉一个「占比刚好 1/10 多一点」的答案的概率是 0.9^100 ≈ 2.7e-5，
//         乘上 dat16/dat17/dat21 里的 1e5 个询问，平均要漏掉 ~2.7 个答案，SPJ 一定会抓到。
//         300 次时是 0.9^300 ≈ 2e-14，配上 1e5 个询问仍然安全。
// 改动 2：map<int, vector<int>> → 离散化 + 出现位置表
//         原来每次 check 里有 pos.find(x)、pos[x] 各一次，等于每采样一次最多 3 次 map 查找；
//         dat12（1e5 次询问 × 全是互不相同的数）光 map 查找就要 5s，直接 TLE。
//         换成数组下标访问后这部分开销基本消失。
// 改动 3：同一个询问里同一个值只统计一次（vis 时间戳）
// 改动 4：O(1) 剪枝：这个值在整个序列里出现次数都不够时，直接跳过二分统计
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 300; // 改动 1：采样次数

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
        cin >> a[i];

    // 改动 2：离散化 + 出现位置表（替代 map<int, vector<int>>）
    vector<int> ys = a;
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = ys.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = lower_bound(ys.begin(), ys.end(), a[i]) - ys.begin();
    vector<int> st(m + 1, 0);
    for (int i = 0; i < n; i++)
        st[id[i] + 1]++;
    for (int v = 0; v < m; v++)
        st[v + 1] += st[v];
    vector<int> flat(n);
    {
        vector<int> cur(st.begin(), st.end() - 1);
        for (int i = 0; i < n; i++)
            flat[cur[id[i]]++] = i; // 0-indexed 位置，天然递增
    }

    vector<int> vis(m, -1); // 改动 3：记录某个值在第几次询问里已经被统计过
    int qi = 0;
    while (Q--)
    {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        l--, r--;
        int len = r - l + 1, need = len * p; // 条件等价于 cnt * q > need
        qi++;
        int ans = -1;
        for (int i = 0; i < M; i++)
        {
            int pos = randINT(l, r);
            int v = id[pos];
            if (vis[v] == qi)
                continue;
            vis[v] = qi;
            int A = st[v], B = st[v + 1];
            if ((B - A) * q <= need) // 改动 4：全局出现次数都不够 → 剪枝
                continue;
            int cnt = upper_bound(flat.begin() + A, flat.begin() + B, r) -
                      lower_bound(flat.begin() + A, flat.begin() + B, l);
            if (cnt * q > need)
            {
                ans = ys[v];
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
