#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
bool b[N];
void solve(){
    memset(b, 0, sizeof(b));
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        if(!b[x]){
            b[x] = 1;
            ans++;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}