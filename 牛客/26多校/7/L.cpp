#include <bits/stdc++.h>
#define int long long
using namespace std;

// 1:2k-1,d=2,s=1*1
// 2:(1,2)mod3,d=6,s=2*s
// 3:(1,2,3)mod4,d=12,s=3*3
// i:(1,i)mod (i+1) ,d=i*(i+1),s=i*i
void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 5; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((j % i) + 1 == j % (i + 1))
            {
                cerr << i << ' ' << j << '\n';
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}