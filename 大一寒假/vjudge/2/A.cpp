#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct peo{
    ll a, b;
};
const int maxn = 55;
peo arr[maxn];
void solve()
{
    int n;
    cin>>n;
    ll mina = 1e10,minb=1e10,ans=0;
    for (int i = 1; i <= n;i++){
        cin >> arr[i].a;
        mina = min(mina, arr[i].a);
    }   
    for (int i = 1; i <= n;i++){
        cin >> arr[i].b;
        minb = min(minb, arr[i].b);
    }
    for (int i = 1; i <= n;i++){
        ans += max(arr[i].a - mina, arr[i].b - minb);
    }
    cout << ans << endl;
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