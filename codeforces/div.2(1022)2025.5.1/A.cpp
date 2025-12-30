#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int k = n - 1;
    int ans = 0;
    while(k>0){
        ans += k;
        k -= 2;
    }
    cout << ans + 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}