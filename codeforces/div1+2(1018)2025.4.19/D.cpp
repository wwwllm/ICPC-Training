#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<ll, int> X,Y;
    for (int i = 1; i <= n;i++){
        int x, y;
        cin >> x >> y;
        X[x]++;
        Y[y+x]++;
    }
    int s, t;
    for(auto [n,cnt]:X)
        if(cnt&1)
            s = n;
    for(auto [n,cnt]:Y)
        if(cnt&1)
            t = n-s;
    cout << s << ' ' << t << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}