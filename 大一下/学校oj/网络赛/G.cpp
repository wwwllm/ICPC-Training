#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int score = a;
    if (a > 80)
        score += b;
    if (b > 40)
        score += c;
    if (score >= 250)
        cout << 1 << endl;
    else if (score >= 220)
        cout << 2 << endl;
    else if (score >= 175)
        cout << 3 << endl;
    else
        cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //   cin>>t;
    while (t--)
        solve();
    return 0;
}