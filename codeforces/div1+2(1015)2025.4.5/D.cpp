#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k, m;
    cin >> n >> m >> k;
    int ans = max(k,n/(m+1));
    for (int i = 0; i < n; i++)
    {
        cout << i % (ans) << ' ';
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}