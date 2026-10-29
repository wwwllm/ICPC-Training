#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> f, siz;
    int cnt;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)];
    }

    int count()
    {
        return cnt;
    }
};
void solve()
{
    int n, d;
    cin >> n >> d;
    int k = n / gcd(n, d);
    DSU dsu(n);
    int dd = 2 * d % n;
    for (int i = 0; i < n; i++)
    {
        dsu.merge(i, (i + dd) % n);
        dsu.merge(i, n - i - 1);
    }
    int ans = 0;
    string s;
    cin >> s;
    vector<array<int, 26>> cnt(n, {0});
    for (int i = 0; i < n; i++)
    {
        cnt[dsu.find(i)][s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++)
    {
        if (dsu.find(i) == i)
        {
            int ma = 0, sum = 0;
            for (int j = 0; j < 26; j++)
            {
                sum += cnt[i][j];
                ma = max(cnt[i][j], ma);
            }
            ans += sum - ma;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}