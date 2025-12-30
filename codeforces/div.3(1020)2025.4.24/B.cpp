#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i <=x-1;i++)
        cout << i << ' ';
    for (int i = n-1; i >= x;i--)
        cout << i << ' ';
    cout << endl;
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