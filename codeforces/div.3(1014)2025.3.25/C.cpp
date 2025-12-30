#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
void solve()
{
    int n;
    cin >> n;
    if(n&1)
        for (int i = n; i >= 1;i--)
            cout << i << ' ';
    else
        cout << -1;
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