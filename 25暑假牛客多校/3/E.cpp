#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e6 + 10;
vector<int> prime, st(N + 1);
void init()
{
    for (int i = 2; i <= N; i++)
    {
        if (st[i] == 0)
            prime.push_back(i);
        for (auto p : prime)
        {
            if (i * p > N)
                break;
            st[i * p] = 1;
            if (i % p == 0)
                break;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &x : a)
        cin >> x;
        
    if (n & 1)
    {
        cout << "YES\n";
        return;
    }

    for (auto x : a)
    {
        for (auto p : prime)
        {
            if (p > x)
                break;
            while (x % p == 0)
            {
                mp[p]++;
                x /= p;
            }
        }
        if (x != 1)
        {
            mp[x]++;
        }
    }

    bool ok = 0;
    for (auto [p, v] : mp)
    {
        if (v & 1)
            ok = 1;
    }

    if (ok)
        cout << "NO\n";
    else
        cout << "YES\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}