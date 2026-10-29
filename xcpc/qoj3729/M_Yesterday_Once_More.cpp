#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
const int N = 1e5;
void solve()
{
    int n;
    cin >> n;
    cout << 10 * n - 2 << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << "RDLD";
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << "URRD";
    }
    for (int i = 0; i < n; i++)
        cout << "L";
    cout << "DL";
    for (int i = 0; i < n; i++)
        cout << "D";
    cout << '\n';
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