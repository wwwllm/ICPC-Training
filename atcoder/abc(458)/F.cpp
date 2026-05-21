#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
struct Mat
{
    int n;
    vector<vector<int>> M;
    Mat(int r) : n(r), M(r, vector<int>(r)) {};
    Mat unit()
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
            res.M[i][i] = 1;
        return res;
    }
    Mat operator*(const Mat &b) const
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.M[i][j] += M[i][k] * b.M[k][j] % mod;
                    res.M[i][j] %= mod;
                }
            }
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << M[i][j] << " \n"[j == n - 1];
            }
        }
    }
};
Mat exp(Mat a, int b)
{
    Mat ans(a.n);
    ans = ans.unit();
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
struct AC
{
    static const int ALPHABET = 26;
    struct Node
    {
        int len, link;
        int f = 0;
        array<int, ALPHABET> nxt;
        Node() : len(0), link(0), nxt{} {};
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
        t[p].f = 1;
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
                    t[next(x, i)].f |= t[t[next(x, i)].link].f;
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
    int n, k;
    cin >> n >> k;
    AC ac;
    vector<int> e;
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        e.push_back(ac.insert(s));
    }
    ac.work();
    int m = ac.size();
    Mat M(m);
    auto &t = ac.t;
    for (int i = 1; i < m; i++)
    {
        if (t[i].f)
            continue;
        for (int c = 0; c < 26; c++)
        {
            int v = ac.next(i, c);
            if (t[v].f)
                continue;
            M.M[i][v]++;
        }
    }
    M = exp(M, n);
    int ans = 0;
    for (int i = 1; i < m; i++)
    {
        (ans += M.M[1][i]) %= mod;
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