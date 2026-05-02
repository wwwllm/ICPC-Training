#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SAM
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link, cnt;
        array<int, ALPHABET> nxt;
        Node() : len{}, link{}, nxt{}, cnt(0) {};
    };
    vector<Node> t;
    vector<int> ind;
    SAM() { init(); };
    void init()
    {
        ind.assign(2, 0);
        t.assign(2, Node());
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int newNode()
    {
        t.emplace_back();
        ind.emplace_back(0);
        return t.size() - 1;
    }
    int insert(int p, int c)
    {
        if (next(p, c))
        {
            int q = next(p, c);
            if (t[q].len == t[p].len + 1)
                return q;
            int r = newNode();
            t[r].len = t[p].len + 1;
            t[r].link = link(q);
            if (link(r))
                ind[link(r)]++;
            if (link(q))
                ind[link(q)]--;
            t[r].nxt = t[q].nxt;
            t[q].link = r;
            ind[r]++;
            while (t[p].nxt[c] == q)
            {
                t[p].nxt[c] = r;
                p = link(p);
            }
            return r;
        }
        int cur = newNode();
        t[cur].len = t[p].len + 1;
        t[cur].cnt = 1;
        while (!next(p, c))
        {
            t[p].nxt[c] = cur;
            p = link(p);
        }
        t[cur].link = insert(p, c);
        if (link(cur))
            ind[link(cur)]++;
        return cur;
    }
    void topu()
    {
        queue<int> q;
        for (int i = 1; i < t.size(); i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            int v = link(u);
            t[v].cnt += t[u].cnt;
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
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
signed main()
{
    string s;
    cin >> s;
    SAM sam;
    int last = 1;
    for (auto c : s)
    {
        last = sam.insert(last, c - 'a');
    }
    sam.topu();
    auto &t = sam.t;
    int ans = 0;
    for (auto u : t)
    {
        if (u.cnt > 1)
            ans = max(ans, u.len * u.cnt);
    }
    cout << ans << '\n';
    return 0;
}