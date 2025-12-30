#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/2053/D
const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), aa, bb;
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    aa = a, bb = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * min(a[i], b[i])) % mod;
    }
    cout << ans << ' ';
    while (q--)
    {
        int op, x;
        cin >> op >> x;
        x--;
        if (op == 1)
        {
            int pos = upper_bound(a.begin(), a.end(), aa[x]) - a.begin() - 1;
            int u = min(a[pos], b[pos]);
            a[pos]++, aa[x]++;
            int v = min(a[pos], b[pos]);
            ans = (ans * exp(u, mod - 2) % mod * v) % mod;
        }
        else
        {
            int pos = upper_bound(b.begin(), b.end(), bb[x]) - b.begin() - 1;
            int u = min(a[pos], b[pos]);
            b[pos]++, bb[x]++;
            int v = min(a[pos], b[pos]);
            ans = (ans * exp(u, mod - 2) % mod * v) % mod;
        }
        cout << ans << " \n"[q == 0];
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