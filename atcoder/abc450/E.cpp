#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 2e18;
void solve()
{
    string X, Y;
    int q;
    cin >> X >> Y >> q;
    vector<int> len(100);
    len[1] = X.size(), len[2] = Y.size();
    vector<array<int, 26>> cnt(101);
    for (auto c : X)
        cnt[1][c - 'a']++;
    for (auto c : Y)
        cnt[2][c - 'a']++;
    for (int i = 3; i <= 100; i++)
    {
        len[i] = min(len[i - 1] + len[i - 2], inf);
        for (int j = 0; j < 26; j++)
        {
            cnt[i][j] = min(inf, cnt[i - 1][j] + cnt[i - 2][j]);
        }
    }
    auto query = [&](auto &&self, int idx, int cur, char c) -> int
    {
        // cout << idx << ' ' << cur << '\n';
        if (cur == 0)
            return 0;
        int res = 0;
        if (idx == 1)
        {
            for (int i = 0; i < min(len[idx], cur); i++)
            {
                if (X[i] == c)
                    res++;
            }
            return res;
        }
        if (idx == 2)
        {
            for (int i = 0; i < min(len[idx], cur); i++)
                if (Y[i] == c)
                    res++;
            return res;
        }
        if (cur <= len[idx - 1])
            return self(self, idx - 1, cur, c);
        else
            return self(self, idx - 2, cur - len[idx - 1], c) + cnt[idx - 1][c - 'a'];
    };
    while (q--)
    {
        int l, r;
        char c;
        cin >> l >> r >> c;
        int ans = query(query, 100, r, c) - query(query, 100, l - 1, c);
        cout << ans << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}