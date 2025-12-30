#include <bits/stdc++.h>
#define int long long
using namespace std;

// int gcd(int x, int y)
// {
//     return y ? gcd(y, x % y) : x;
// }
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &X : a)
        cin >> X;
    int cnt = 0;
    int g = a[0];
    for (auto it : a)
        g = gcd(g, it);
    for (auto it : a)
    {
        if (it == g)
        {
            cnt++;
        }
    }
    if (cnt != 0)
    {
        cout << n - cnt << '\n';
    }
    else
    {
        auto bfs = [&]() -> int
        {
            set<int> S;
            queue<array<int, 2>> q;
            for (auto it : a)
                q.push({it, 0}), S.insert(it);
            while (q.size())
            {
                auto [u, cnt] = q.front();
                q.pop();
                if (u == g)
                {
                    return cnt;
                }
                for (auto it : a)
                {
                    int tm = gcd(u, it);
                    if (S.find(tm) == S.end())
                    {
                        S.insert(tm);
                        q.push({tm, cnt + 1});
                    }
                }
            }
            return -1;
        };
        int res = bfs();
        cout << n + res - 1 << '\n';
    }
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