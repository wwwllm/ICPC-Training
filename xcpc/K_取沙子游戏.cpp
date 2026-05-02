#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n & 1)
    {
        cout << "Alice\n";
    }
    else
    {
        while (n % 2 == 0)
        {
            n /= 2;
            k /= 2;
        }
        if (k)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
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