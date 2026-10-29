#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105386/problem/H
const int mod = 998244353;
namespace NTT
{
    const int mod = 998244353, g = 3;
    int exp(int a, int b)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
                ans = a * ans % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ans;
    }
    void dft(vector<int> &a)
    {
        int n = a.size();
        vector<int> rev(n);
        for (int i = 0; i < n; i++)
        {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        }
        for (int k = 1; k < n; k <<= 1)
        {
            int wn = exp(g, (mod - 1) / (2 * k));
            for (int i = 0; i < n; i += 2 * k)
            {
                int w = 1;
                for (int j = 0; j < k; j++)
                {
                    int u = a[i + j], v = a[i + j + k] * w % mod;
                    a[i + j] = (u + v) % mod;
                    a[i + j + k] = (u - v + mod) % mod;
                    (w *= wn) %= mod;
                }
            }
        }
    }
    void idft(vector<int> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        int inv = exp(n, mod - 2);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= inv) %= mod;
        }
    }
    vector<int> mul(vector<int> a, vector<int> b)
    {
        int tot = a.size() + b.size() - 1;
        int n = 1;
        while (n < tot)
        {
            n <<= 1;
        }
        a.resize(n), b.resize(n);
        dft(a), dft(b);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= b[i]) %= mod;
        }
        idft(a);
        a.resize(tot);
        return a;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> sta;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (sta.size() && a[sta.back()] <= a[i])
        {
            sta.pop_back();
        }
        if (sta.size())
            l[i] = sta.back();
        else
            l[i] = 0;
        sta.push_back(i);
    }
    sta.clear();
    for (int i = n; i >= 1; i--)
    {
        while (sta.size() && a[sta.back()] <= a[i])
            sta.pop_back();
        if (sta.size())
            r[i] = sta.back();
        else
            r[i] = n + 1;
        sta.push_back(i);
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i]].push_back(i);
    }
    vector<int> c(n + 1);
    for (auto &[x, p] : mp)
    {
        int m = p.size();
        int L, R;
        for (int i = 0; i < m;)
        {
            L = l[p[i]];
            R = r[p[i]];
            vector<int> A;
            int pre = L;
            int cx = 0;
            while (i < m && p[i] <= R)
            {
                A.push_back(p[i] - pre);
                pre = p[i];
                i++;
                cx++;
            }
            A.push_back(R - pre);
            auto rA = A;
            ranges::reverse(A);
            auto res = NTT::mul(rA, A);
            for (int j = 0; j < cx; j++)
            {
                int k = cx - j;
                (c[k] += res[j]) %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        (ans += i * c[i] % mod * c[i] % mod) %= mod;
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