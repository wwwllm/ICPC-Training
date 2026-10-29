#include <bits/stdc++.h>
#define int long long
using namespace std;

// a[i]<0;sum+=a[i]*i;
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n;i++){
        int a;
        cin >> a;
        if(a>0)
            ans += a;
        else
            ans += a * i;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t=1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}
