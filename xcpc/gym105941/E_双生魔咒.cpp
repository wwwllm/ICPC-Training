#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105941
struct Trie
{
    vector<array<int, 26>> nxt;
    vector<int> cnt, pass;
    Trie()
    {
        init();
    };
    void init()
    {
        nxt.assign(1, {});
        cnt.assign(1, 0);
        pass.assign(1, 0);
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
};
void solve()
{
    int n;
    cin >> n;
    Trie T;
    for (int i = 1; i <= 2 * n; i++)
    {
        string s;
        cin >> s;
        T.insert(s);
    }
    int ans = 0;
    auto pass = T.pass;
    for (int i = 1; i < pass.size(); i++)
    {
        ans += pass[i] / 2 * (pass[i] - pass[i] / 2);
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