#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>t(n);
    for(int i=0;i<n;i++){
        int ti,w;
        cin>>w>>ti;
        t[i]=ti+k-w;
    }
    ranges::sort(t);
    for(int i=1;i<n;i++){
        t[i]=max(t[i],t[i-1]+1);
    }
    cout<<t.back()<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}