#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "YES\n"
             << 1 << '\n';
    }
    else if (n == 3)
    {
        cout << "YES\n1 2 3\n";
    }
    else
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