#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    for(auto x:s){
        if(x=='A')a++;
        else if(x=='B')b=min(a,b+1);
        else c=min(c+1,b);
    }
    cout<<c<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}