#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 998244353;
struct AC
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        bool end;
        int out;
        array<int, ALPHABET> nxt;
        Node() : len(0), link(0), end(0), out(0), nxt{} {};
    };
    vector<Node> t;
    AC()
    {
        init();
    }
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
    int insert(string &a)
    {
        int p = 1;
        for (auto c : a)
        {
            int u = c - 'a';
            if (next(p, u) == 0)
            {
                t[p].nxt[u] = newNode();
                t[next(p, u)].len = t[p].len + 1;
            }
            p = next(p, u);
        }
        t[p].end = 1;
        return p;
    }
    void work()
    {
        queue<int> q;
        q.push(1);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET; i++)
            {
                if (next(x, i) == 0)
                {
                    t[x].nxt[i] = next(link(x), i);
                }
                else
                {
                    t[next(x, i)].link = next(link(x), i);
                    int y = next(x, i);
                    int f = link(y);
                    if (t[f].end)
                        t[y].out = f;
                    else
                        t[y].out = t[f].out;
                    q.push(next(x, i));
                }
            }
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    vector<int> pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = min(pre[i - 1], a[i]);
    }
    suf[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
    {
        suf[i] = max(suf[i + 1], a[i]);
    }
    AC ac;
    vector<int> id(q);
    for (int i = 0; i < q; i++)
    {
        string tmp;
        cin >> tmp;
        id[i] = ac.insert(tmp);
    }
    ac.work();
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i];
        p[i] = (p[i] % mod + mod) % mod;
    }
    int cur = 1;
    int m = ac.size();
    vector<int> ma(m, -inf);
    vector<int> last(m);
    vector<int> ans(m);
    for (int r = 1; r <= n; r++)
    {
        auto c = s[r] - 'a';
        cur = ac.next(cur, c);
        int u = ac.t[cur].end ? cur : ac.t[cur].out;
        while (u)
        {
            int l = r - ac.t[u].len + 1;
            ma[u] = max(ma[u], suf[r] - pre[l - 1]);
            int lcnt = l - last[u], lsum = (p[l - 1] - p[max(0LL, last[u] - 1)] + 2 * mod) % mod;
            int rcnt = n - r + 1, rsum = (p[n] - p[r - 1] + 2 * mod) % mod;
            ans[u] += (lcnt * rsum % mod - rcnt * lsum % mod + 2 * mod) % mod;
            ans[u] %= mod;
            last[u] = l;
            u = ac.t[u].out;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ma[id[i]] << ' ' << ans[id[i]] << '\n';
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