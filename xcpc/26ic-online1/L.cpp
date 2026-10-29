#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Trie
{
    vector<array<int, 26>> nxt;
    vector<int> cnt, pass, dep;
    Trie()
    {
        init();
    };
    void init()
    {
        nxt.assign(1, {});
        cnt.assign(1, 0);
        pass.assign(1, 0);
        dep.assign(1, 0);
    }
    void insert(const string s)
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
                dep.emplace_back(dep[p] + 1);
            }
            pass[p]++;
            p = nxt[p][x];
        }
        cnt[p]++;
        pass[p]++;
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

void solve()
{
    int n;
    cin >> n;
    Trie t;
    vector<int> res(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 0 ^ i;
        string s;
        cin >> s;
        t.insert(s);
        int p = 0;
        for (auto c : s)
        {
            int u = c - 'a';
            p = t.nxt[p][u];
            if (res[t.pass[p]] < t.dep[p])
            {
                sum -= res[t.pass[p]] ^ t.pass[p];
                res[t.pass[p]] = t.dep[p];
                sum += res[t.pass[p]] ^ t.pass[p];
            }
        }
        cout << sum << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}