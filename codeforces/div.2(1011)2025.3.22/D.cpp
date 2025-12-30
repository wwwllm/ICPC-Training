#include <bits/stdc++.h>
#define ll long long
using namespace std;

//拿取到吃完一盘需要(k+1)操作
//最后拿盘子要在n-k次操作前
//最后2次拿要在n-2*(k+1)+1前
void solve()
{
    int n, k;
    cin >>n >> k;
    priority_queue<ll>pq;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        ll x;
        cin >> x;
        pq.push(x);
        if((n-i+1)%(k+1)==0)
            ans += pq.top(), pq.pop();
    }
    cout << ans << endl;
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