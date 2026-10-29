#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    vector<array<int, 26>> nxt;
    vector<int> cnt, pass;
    vector<vector<int>> end;
    Trie()
    {
        init();
    };
    void init()
    {
        nxt.assign(1, {});
        cnt.assign(1, 0);
        pass.assign(1, 0);
        end.assign(1, {});
    }
    void insert(const string s, int idx)
    {
        int p = 0;
        for (auto c : s)
        {
            int x = c - 'a';
            if (nxt[p][x] == 0)
            {
                nxt[p][x] = nxt.size();
                nxt.emplace_back();
                cnt.emplace_back(0);
                pass.emplace_back(0);
                end.push_back({});
            }
            pass[p]++;
            p = nxt[p][x];
        }
        cnt[p]++;
        pass[p]++;
        end[p].push_back(idx);
    }
    int query(const string s)
    {
        int p = 0;
        for (auto c : s)
        {
            int x = c - 'a';
            if (nxt[p][x] == 0)
                return 0;
            p = nxt[p][x];
        }
        return cnt[p];
    }
    int query_pre(const string s)
    {
        int p = 0;
        for (auto c : s)
        {
            int x = c - 'a';
            if (nxt[p][x] == 0)
                return 0;
            p = nxt[p][x];
        }
        return pass[p];
    }
    bool erase(const string s)
    {
        if (query(s) == 0)
            return 0;
        int p = 0;
        pass[p]--;
        for (auto c : s)
        {
            int x = c - 'a';
            p = nxt[p][x];
            pass[p]--;
        }
        cnt[p]--;
        return 1;
    }
    string kth(int k)
    {
        if (k > pass[0])
            return "";
        int p = 0;
        string res = "";
        while (k > 0)
        {
            if (cnt[p] >= k)
                return res;
            k -= cnt[p];
            for (int i = 0; i < 26; ++i)
            {
                if (nxt[p][i])
                {
                    if (k <= pass[nxt[p][i]])
                    {
                        res += (char)('a' + i);
                        p = nxt[p][i];
                        break;
                    }
                    else
                    {
                        k -= pass[nxt[p][i]];
                    }
                }
            }
        }
        return res;
    }
};
struct SCC
{
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;
    SCC() {};
    SCC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        cur = cnt = 0;
    }
    void add(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfs(int u)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto v : adj[u])
        {
            if (dfn[v] == -1)
            {
                dfs(v);
                low[u] = min(low[v], low[u]);
            }
            else if (bel[v] == -1)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            int v;
            do
            {
                v = stk.back();
                stk.pop_back();
                bel[v] = cnt;
            } while (v != u);
            cnt++;
        }
    }
    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
                dfs(i);
        }
        return bel;
    }
    vector<vector<int>> get_DAG()
    {
        vector nadj(cnt, vector<int>{});
        for (int u = 0; u < n; u++)
        {
            for (auto v : adj[u])
            {
                if (bel[u] != bel[v])
                    nadj[bel[u]].push_back(bel[v]);
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            ranges::sort(nadj[i]);
            nadj[i].erase(unique(nadj[i].begin(), nadj[i].end()), nadj[i].end());
        }
        return nadj;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<array<string, 2>> s(n);
    Trie t;
    for (int i = 0; i < n; i++)
    {
        for (auto op : {0, 1})
        {
            cin >> s[i][op];
            t.insert(s[i][op], i << 1 | op);
        }
    }
    auto nxt = t.nxt;
    SCC adj(n * 6 + 2);
    int cur = n * 2;
    auto new_node = [&]()
    {
        int p = cur;
        cur += 2;
        return p;
    };
    auto dfs = [&](auto &&self, int idx, int u) -> void
    {
        for (auto v : t.end[idx])
        {
            int p = new_node();
            if (u != -1)
            {
                adj.add(u, v ^ 1);
                adj.add(v, u ^ 1);
                adj.add(u, p);
                adj.add(p ^ 1, u ^ 1);
            }
            adj.add(v, p);
            adj.add(p ^ 1, v ^ 1);
            u = p;
        }
        for (int i = 0; i < 26; i++)
        {
            if (nxt[idx][i] == 0)
                continue;
            self(self, nxt[idx][i], u);
        }
    };
    dfs(dfs, 0, -1);
    auto bel = adj.work();
    vector<int> ans(n + 1);
    for (int i = 0; i < bel.size(); i += 2)
    {
        if (bel[i] == bel[i ^ 1])
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = bel[i << 1] < bel[i << 1 | 1];
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << (ans[i] ? "l" : "r");
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
