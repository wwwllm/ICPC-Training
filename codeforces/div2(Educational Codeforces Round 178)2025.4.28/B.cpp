#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n+1),ma(n+1,0),suf(n+2,0);
    for (int i = 1; i <= n;i++)
        cin >> a[i],ma[i]=max(a[i],ma[i-1]);
    for (int i = n; i >= 1;i--)
        suf[i] = a[i] + suf[i + 1];
    for (int k = n; k >= 1;k--)
    {
        cout << suf[k+1] + ma[k] << ' ';
    }
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