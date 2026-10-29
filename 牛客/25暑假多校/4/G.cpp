#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 1e6 + 10;
vector<int> p(N), invp(N);
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void init()
{
    p[0] = 1, invp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }
    for (int i = 1; i < N; i++)
    {
        invp[i] = invp[i - 1] * exp(i, mod - 2) % mod;
    }
}
void solve()
{
    string s;
    cin >> s;
    s = ' ' + s;
    int n = s.size() - 1;
    int b = 0;
    vector<int> p1, p2, pb;
    vector<int> c1(n + 2), c2(n + 2);
    for (int i = 1; i <= n; i++)
    {
        if (b == 0)
        {
            pb.push_back(i);
        }
        if (s[i] == '(')
            p1.push_back(i), b++;
        c1[i] = c1[i - 1] + (s[i] == '(');
        if (s[i] == ')')
            p2.push_back(i), b--;
        c2[i] = c2[i - 1] + (s[i] == ')');
    }
    // pb.push_back(n + 1);

    int ans = exp(2, n / 2) - 1;
    ans *= 2;

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
        {
            int cr = c2[n] - c2[i];
            int cnt = (lower_bound(pb.begin(), pb.end(), i) - pb.begin()) + 1;
            cout << cnt << ' ' << cr << '\n';
            ans = (ans + 2 * cnt * cr % mod) % mod;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (s[i] == ')')
    //     {
    //         int cl = c1[i];
    //         int cnt = pb.end() - lower_bound(pb.begin(), pb.end(), i - 1);
    //         //cout << cnt << ' ' << cl << ' ' << i << '\n';
    //         ans = (ans + cnt * cl % mod) % mod;
    //     }
    // }

    ans = (ans - pb.size() * (pb.size() + 1) / 2 + mod) % mod;
    ans++;
    ans += 30;
    ans %= mod;
    cout << ans << '\n';
    int q = exp(2, n);
    cout << ans * exp(q, mod - 2) % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--)
        solve();
    return 0;
}