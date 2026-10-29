#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], g = gcd(a[i], g);
    for (int i = 0; i < n; i++)
    {
        a[i] /= g;
    }
    vector<int> prime;
    auto get_p = [&](int x)
    {
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                prime.push_back(i);
                while (x % i == 0)
                {
                    x /= i;
                }
            }
        }
        if (x > 1)
            prime.push_back(x);
    };
    get_p(a[0]), get_p(a[1]), get_p(a[2]);
    ranges::sort(prime);
    prime.erase(unique(prime.begin(), prime.end()), prime.end());
    for (auto p : prime)
    {
        vector<int> aa;
        g = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % p != 0)
                aa.push_back(a[i]), g = gcd(g, a[i]);
        }
        if (aa.size() <= 1 || g > 1)
        {
            cout << "YES\n";
            return;
        }
        int m = aa.size();
        vector<int> pre(m), suf(m);
        pre[0] = aa[0];
        for (int i = 1; i < m; i++)
        {
            pre[i] = gcd(pre[i - 1], aa[i]);
        }
        suf[m - 1] = aa[m - 1];
        for (int i = m - 2; i >= 0; i--)
        {
            suf[i] = gcd(suf[i + 1], aa[i]);
        }
        for (int i = 0; i < m; i++)
        {
            int pr = i == 0 ? 0 : pre[i - 1];
            int su = i == m - 1 ? 0 : suf[i + 1];
            if (gcd(pr, su) > 1)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}