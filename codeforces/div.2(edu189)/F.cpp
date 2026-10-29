#include <bits/stdc++.h>
using namespace std;

#define int long long
using i64 = long long;

struct Hash
{
    static constexpr int M1 = 1e9 + 7, M2 = 1e9 + 9;
    static constexpr int B = 131;
    std::vector<int> h1, h2, p1, p2;

    Hash(const std::string &s)
    {
        int n = s.size();
        h1.resize(n + 1);
        h2.resize(n + 1);
        p1.resize(n + 1);
        p2.resize(n + 1);
        p1[0] = p2[0] = 1;
        for (int i = 0; i < n; i++)
        {
            h1[i + 1] = (1LL * h1[i] * B + s[i]) % M1;
            h2[i + 1] = (1LL * h2[i] * B + s[i]) % M2;
            p1[i + 1] = 1LL * p1[i] * B % M1;
            p2[i + 1] = 1LL * p2[i] * B % M2;
        }
    }

    // 返回闭区间 [l, r] 的哈希值，索引从 0 开始
    std::pair<int, int> get(int l, int r)
    {
        int r1 = (h1[r + 1] - 1LL * h1[l] * p1[r - l + 1] % M1 + M1) % M1;
        int r2 = (h2[r + 1] - 1LL * h2[l] * p2[r - l + 1] % M2 + M2) % M2;
        return {r1, r2};
    }
};
void solve()
{
    int n, len, k;
    string s;
    cin >> n >> len >> k >> s;
    if (len * k > n)
    {
        cout << "NO\n";
        return;
    }
    if (k == 1)
    {
        cout << "YES\n"
             << s << '\n';
        return;
    }

    Hash hash(s);
    array<int, 2> res = {-1, -1};
    auto cmp = [&](array<int, 2> a, array<int, 2> b) -> int
    {
        int l = 0, r = min(a[1], b[1]) + 1;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (hash.get(a[0], a[0] + mid - 1) == hash.get(b[0], b[0] + mid - 1))
                l = mid;
            else
                r = mid;
        }
        if (l == min(a[1], b[1]))
        {
            return a[1] < b[1];
        }
        return s[a[0] + l] < s[b[0] + l];
    };
    for (int l = 0; l < n; l++)
    {
        int cntl = l / len;
        if (cntl == 0 && l != 0)
            continue;
        int need = max(0LL, k - cntl - 1) * len;
        int r = n - need - 1;
        if (r - l + 1 < len)
            continue;
        if (res == array<int, 2>{-1, -1} || cmp(res, {l, r - l + 1}))
        {
            res = {l, r - l + 1};
        }
    }
    if (res != array<int, 2>{-1, -1})
        cout << "YES\n"
             << s.substr(res[0], res[1]) << '\n';
    else
        cout << "NO\n";
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