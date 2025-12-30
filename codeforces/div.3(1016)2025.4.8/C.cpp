#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
    if (x == 1)
        return 0;
    if (x == 2)
        return 1;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    if ((is_prime(n) && k == 1) || (n == 1 && k == 2))
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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