#include <bits/stdc++.h>
#define int long long
using namespace std;

// x^y+y>x
// x^y>x-y
// y>x&y
void solve()
{
    int x;
    cin >> x;
    if ((x & (x - 1)) == 0 || ((x + 1) & x) == 0)
    {
        cout << -1 << endl;
        return;
    }
    int k=0;
    while(x>(1<<k))
        k++;
    k--;
    int y = (1 << k) - 1;
    cout << y << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
