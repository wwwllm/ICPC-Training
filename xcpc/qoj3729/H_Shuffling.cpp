#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 998244353;

using i64 = long long;

struct Hash
{
    static constexpr int M1 = 1e9 + 7, M2 = 1e9 + 9;
    static constexpr int B = 131;
    vector<int> h1, h2, p1, p2;

    Hash() {};
    Hash(const string &s)
    {
        int n = s.size();
        h1.resize(n + 1);
        h2.resize(n + 1);
        p1.resize(n + 1);
        p2.resize(n + 1);

        p1[0] = p2[0] = 1;

        for (int i = 0; i < n; i++)
        {
            h1[i + 1] = (h1[i] * B + s[i]) % M1;
            h2[i + 1] = (h2[i] * B + s[i]) % M2;

            p1[i + 1] = p1[i] * B % M1;
            p2[i + 1] = p2[i] * B % M2;
        }
    }

    pair<int, int> get(int l, int r)
    {
        int r1 = (h1[r + 1] - h1[l] * p1[r - l + 1] % M1 + M1) % M1;
        int r2 = (h2[r + 1] - h2[l] * p2[r - l + 1] % M2 + M2) % M2;

        return {r1, r2};
    }

    pair<int, int> add(pair<int, int> h1, pair<int, int> h2, int l2)
    {
        int r1 = (h1.first * p1[l2] + h2.first) % M1;
        int r2 = (h1.second * p2[l2] + h2.second) % M2;

        return {r1, r2};
    }
};

void solve()
{
    int k, t;
    cin >> k >> t;
    string s;
    cin >> s;
    int n = 1LL << k;
    s = s + s;
    Hash hash(s);
    t %= k;
    int res = 0;
    vector<int> d(k + 1);
    vector H(k + 1, vector<pair<int, int>>(n));
    for (int i = 0; i < n; i++)
    {
        H[0][i] = hash.get(i, i);
    }
    for (int j = 1; j <= k; j++)
    {
        int bit = (j - 1 - t + k) % k;
        d[j] = 1LL << bit;
        int len = 1LL << (j - 1);
        for (int i = 0; i < n; i++)
        {
            auto H1 = H[j - 1][i];
            auto H2 = H[j - 1][(i + d[j]) & (n - 1)];
            H[j][i] = hash.add(H1, H2, len);
        }
    }
    auto cmp = [&](int a, int b) -> bool
    {
        if (H[k][a] == H[k][b])
        {
            return 0;
        }
        int x = a, y = b;
        for (int j = k; j >= 1; j--)
        {
            if (H[j - 1][x] == H[j - 1][y])
            {
                x = (x + d[j]) & (n - 1);
                y = (y + d[j]) & (n - 1);
            }
        }
        return s[x] > s[y];
    };
    for (int i = 0; i < n; i++)
    {
        if (cmp(res, i))
        {
            res = i;
        }
    }
    string ans = s.substr(res, n);
    auto calc = [&](string &s)
    {
        string res = "";
        for (int i = 0, j = n / 2; i < n / 2 && j < n; i++, j++)
        {
            res += s[i];
            res += s[j];
        }
        return res;
    };
    while (t--)
    {
        ans = calc(ans);
    }
    cout << ans << '\n';
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