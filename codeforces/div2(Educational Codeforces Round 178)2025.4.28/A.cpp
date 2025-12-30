#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if((a+b+c)%3==0){
        if(a<=(a+b+c)/3&&b<=(a+b+c)/3)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}