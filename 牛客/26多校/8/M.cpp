#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Trie
{
    int m;
    int cnt = 0;
    vector<int> fa;
    vector<array<int, 26>> nxt;
    vector<vector<int>> tim;
    vector<int> vis;
    vector<int> son;
    vector<int> cur;
    priority_queue<array<int, 2>> pq;
    Trie(int m) : m(m)
    {
        init();
    };
    void init()
    {
        nxt.assign(1, {});
        vis.assign(1, 1);
        son.assign(1, 0);
        tim.assign(1, {});
        cur.assign(1, 0);
        fa.assign(1, -1);
        cnt = 0;
    }
    int newnode(int f)
    {
        int u = nxt.size();
        nxt.push_back({});
        fa.push_back(f);
        vis.push_back(0);
        son.push_back(0);
        tim.push_back({});
        cur.push_back(0);
        return u;
    }
    void insert(const string &s, int ti)
    {
        int p = 0;
        for (auto c : s)
        {
            int x = c - 'a';
            if (nxt[p][x] == 0)
            {
                nxt[p][x] = newnode(p);
            }
            p = nxt[p][x];
            tim[p].push_back(ti);
        }
    }
    int get_nxt(int u)
    {
        if (cur[u] == tim[u].size())
        {
            return inf;
        }
        return tim[u][cur[u]];
    }
    int calc(const string &s, int ti)
    {
        int p = 0;
        int res = 0;
        for (auto c : s)
        {
            int x = c - 'a';
            int u = nxt[p][x];
            if (!vis[u])
            {
                res++;
                vis[u] = 1;
                cnt++;
                son[p]++;
            }
            p = u;
            while (cur[u] < tim[u].size() && tim[u][cur[u]] <= ti)
                cur[u]++;
            push(u);
        }
        erase();
        return res;
    }
    void push(int u)
    {
        if (u == 0)
            return;

        if (vis[u] && son[u] == 0)
        {
            pq.push({get_nxt(u), u});
        }
    }
    void erase()
    {
        while (pq.size() && cnt > m)
        {
            auto [ti, u] = pq.top();
            pq.pop();
            if (!vis[u])
                continue;
            if (son[u])
                continue;
            if (get_nxt(u) != ti)
                continue;
            vis[u] = 0;
            cnt--;
            son[fa[u]]--;
            push(fa[u]);
        }
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    Trie t(m);
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t.insert(a[i], i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += t.calc(a[i], i);
    }
    cout << ans << '\n';
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
