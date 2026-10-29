#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105922    
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a & 1)
        swap(a, b);
    if (a > b)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';
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