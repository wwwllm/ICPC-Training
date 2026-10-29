#include <bits/stdc++.h>
#define int long long
using namespace std;

// b*n-c<0--n<c/b
// c-n*b<c
// f(n)不为整数
void solve()
{
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    if (c % b == 0)
        ans = c / b - 1;
    else
        ans = c / b;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            if ((c - i) % b == 0 && (c - i) / b >= 1)
                ans--;
            if ((c - a / i) % b == 0 && i * i != a && (c - a / i) / b >= 1)
                ans--;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}