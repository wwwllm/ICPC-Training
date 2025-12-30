#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x:a)
        cin >> x;
    sort(a.begin(),a.end());
    if(n==k){
        cout << 0 << endl;
        return;
    }
    int m = n - k;
    cout << a[n - 1 - (m - 1) / 2] - a[(m - 1) / 2] + 1 << endl;
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