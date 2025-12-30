#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int x, y, a;
    cin >> x >> y >> a;
    int res = a % (x + y);
    if(res<x)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}