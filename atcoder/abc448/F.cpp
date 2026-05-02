#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<array<int,2>>p(n);
    for(auto &[x,y]:p){
        cin>>x>>y;
    }
    int len=2e7/sqrt(n);
    vector<int>pos(n);
    ranges::iota(pos,0);
    ranges::sort(pos,[&](int i,int j){
        auto [xi,yi]=p[i];
        auto [xj,yj]=p[j];
        int pi=xi/len,pj=xj/len;
        if(pi==pj){
            if(pi&1)return yi>yj;
            else return yi<yj;
        }
        else
            return pi<pj;
    });
    int s=0;
    while(pos[s]!=0)s++;
    while(pos[(s+1)%n]!=0){
        cout<<pos[s]+1<<" ";
        s=(s+1)%n;
    }
    cout<<pos[s]+1<<' ';
    cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}