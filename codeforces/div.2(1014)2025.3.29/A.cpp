#include <bits/stdc++.h>
using namespace std;

// gcd(x,y)=gcd(x,x-y);
void solve()
{
    int n;
    int mi=1e9,ma=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ma = max(ma, x);
        mi = min(mi, x);
    }
    cout << ma - mi << endl;
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