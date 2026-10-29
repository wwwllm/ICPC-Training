#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int x, int t)
{   if(t<0)
        return 0;
    return (x + x - t + 1) * t / 2;
}
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    for (int i = 1; i <= min(n,y); i++)
    {
        int sum1 = (x + i) * (min(n,y) - i +1);
        int sum2 = f(x+i-1, min(x+i-1, n - y));
        ans = max(ans, sum1 + sum2);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
