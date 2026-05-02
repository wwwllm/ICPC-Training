#include<bits/stdc++.h>
#define int long long
using namespace std;

//https://codeforces.com/gym/105911/problem/G
const int inf =1e9;
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<array<int,3>>e(m);
    vector dp(31,vector<int>(n+1));
    for(auto &[u,v,w]:e)cin>>u>>v>>w;
    for(int i=1;i<31;i++){
        for(auto [u,v,w]:e)dp[i][u]=max(dp[i][u],min(inf,dp[i-1][v]*w+w-1));
    }
    while(q--){
        int p,w;
        cin>>p>>w;
        for(int i=0;i<31;i++){
            if(dp[i][p]>=w){
                cout<<i<<'\n';
                break;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}