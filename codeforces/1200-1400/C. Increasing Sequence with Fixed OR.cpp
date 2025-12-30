#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/1988/C
ll lowbit(ll x)
{
    return x & -x;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> nbit;
    ll temp = n;
    while (temp)
    {
        nbit.push_back(lowbit(temp));
        temp -= lowbit(temp);
    }
    int m = nbit.size();
    if (m > 1)
    {
        cout << m + 1 << '\n';
        for (int i = m - 1; i >= 0; i--)
            cout << n - nbit[i] << ' ';
        cout << n << " \n";
    }
    else
        cout << "1\n"
             << n << '\n';
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