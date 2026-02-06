#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    n = n % 10;
    if (n == 0)
    {
        cout << "1\n";
    }
    else if (n % 2 == 0)
    {
        cout << "5\n";
    }
    else if (n == 5)
    {
        cout << "2\n";
    }
    else
    {
        cout << "10\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}