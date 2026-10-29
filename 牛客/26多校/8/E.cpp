#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
using i128 = __int128_t;
struct SAM
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        int best;
        array<int, ALPHABET> nxt;
        Node() : len{}, link{}, nxt{}, best{} {};
    };
    vector<int> safe;
    vector<Node> t;
    SAM(vector<int> &safe) : safe(safe) { init(); };
    void init()
    {
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        return t.size() - 1;
    }
    int insert(int p, int c, int idx)
    {
        if (next(p, c))
        {
            int q = next(p, c);
            if (t[q].len == t[p].len + 1)
            {
                t[q].best = max(t[q].best, safe[idx]);
                return q;
            }
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = link(q);
            t[r].nxt = t[q].nxt;
            t[q].link = r;
            while (t[p].nxt[c] == q)
            {
                t[p].nxt[c] = r;
                p = link(p);
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        t[cur].best = max(t[cur].best, safe[idx]);
        while (!next(p, c))
        {
            t[p].nxt[c] = cur;
            p = link(p);
        }
        t[cur].link = insert(p, c, idx);
        return cur;
    }
    void build()
    {
        int n = t.size();
        vector<int> p(n);
        ranges::iota(p, 0);
        ranges::sort(p, [&](int a, int b)
                     { return t[a].len > t[b].len; });
        for (int i = 0; i < n; i++)
        {
            t[link(p[i])].best = max(t[p[i]].best, t[link(p[i])].best);
        }
    }
    int next(int p, int x)
    {
        return t[p].nxt[x];
    }
    int link(int p)
    {
        return t[p].link;
    }
    int len(int p)
    {
        return t[p].len;
    }
    int size()
    {
        return t.size();
    }
};
void solve()
{
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    ranges::reverse(s);
    ranges::reverse(p);
    int cur = -1;
    auto kmp = [&](string &s) -> vector<int>
    {
        int n = s.size();
        vector<int> f(n + 1);
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j && s[i] != s[j])
                j = f[j];
            j += (s[i] == s[j]);
            f[i + 1] = j;
        }
        return f;
    };
    auto f = kmp(p);
    vector<int> safe(n);
    {
        int pre = -1;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j && s[i] != p[j])
            {
                j = f[j];
            }
            j += (s[i] == p[j]);
            if (j == m)
            {
                pre = i - m + 1;
                j = f[j];
            }
            safe[i] = i - pre;
        }
    }
    vector<int> pos(n);
    SAM sam(safe);
    for (int i = 0; i < n; i++)
    {
        pos[i] = i == 0 ? sam.insert(1, s[i] - 'a', i) : sam.insert(pos[i - 1], s[i] - 'a', i);
    }
    sam.build();
    int N = sam.t.size();
    vector adj(N + 1, vector<int>());
    for (int i = 2; i < N; i++)
    {
        adj[sam.link(i)].push_back(i);
    }
    auto dfs = [&](auto &&self, int u) -> int
    {
        int fa = sam.link(u);
        int cut = min(sam.t[u].best, sam.len(u));
        if (cut <= sam.len(fa))
            return 1;
        if (cut < sam.len(u))
            return cut - sam.len(fa) + 1;
        int res = 1;
        for (auto v : adj[u])
        {
            (res *= self(self, v)) %= mod;
        }
        return (res + sam.len(u) - sam.len(fa)) % mod;
    };
    int ans = 1;
    for (auto v : adj[1])
        ans = ans * dfs(dfs, v) % mod;
    cout << (ans - 1 + mod) % mod << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
