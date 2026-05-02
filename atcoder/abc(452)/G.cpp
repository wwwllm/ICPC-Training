#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SAM
{
    static const int ALPHABET = 10;
    struct Node
    {
        int len, link;
        array<int, ALPHABET> nxt;
        Node() : len{}, link{}, nxt{} {};
    };
    vector<Node> t;
    SAM() { init(); };
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
        while (!next(p, c))
        {
            t[p].nxt[c] = cur;
            p = link(p);
        }
        t[cur].link = insert(p, c);
        return cur;
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
    int n;
    cin >> n;
    vector<int> a(n);
    SAM sam;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int last = 1;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        int cnt = j - i;
        if (cnt == a[i])
        {
            last = sam.insert(last, a[i]);
        }
        else if (cnt < a[i])
        {
            last = 1;
        }
        else
        {
            last = sam.insert(last, a[i]);
            last = 1;
            last = sam.insert(last, a[i]);
        }
        i = j - 1;
    }
    auto &t = sam.t;
    int cnt = 0;
    for (int i = 2; i < t.size(); i++)
    {
        int j = sam.link(i);
        cnt += t[i].len - t[j].len;
    }
    cout << cnt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}