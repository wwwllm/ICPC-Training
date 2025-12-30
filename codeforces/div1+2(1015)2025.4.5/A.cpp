#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n&1){
        cout << n << ' ' << 1 << ' ';
        for (int i = 2; i <= n - 1;i++)
            cout << i << ' ';
        cout << endl;
    }
    else
        cout << -1 << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}