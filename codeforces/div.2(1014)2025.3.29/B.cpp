#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
void solve()
{
    int n;
    cin >> n;
    int a0 = 0, a1 = 0, b1 = 0, b0 = 0;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        if (x == '0')
        {
            i & 1 ? a1++ : a0++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        if (x == '0')
        {
            i & 1 ? b1++ : b0++;
        }
    }
    if (a1 + b0 >= (n + 1) / 2 && a0 + b1 >= n / 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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