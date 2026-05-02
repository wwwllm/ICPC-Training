#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

//https://codeforces.com/gym/105992/problem/I
const int mod=998244353;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector adj(n+1,vector<int>());
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int root=1;
    vector dp(n+1,vector<int>(n+1));
    vector siz(n+1,0);
    function<void(int,int)> f=[&](int u,int fa){
        siz[u]=0;
        vector<int>cnt(n+1);
        cnt[0]=1;
        for(auto v:adj[u]){
            if(v==fa)continue;
            f(v,u);
            vector<int> ncnt(n+1,0);
            for(int i=0;i<=siz[u];i++){
                for(int j=0;j<=siz[v];j++){
                    ncnt[i+j]+=cnt[i]*dp[v][j]%mod;
                    ncnt[i+j]%=mod;
                }
            }
            cnt=ncnt;
            siz[u]+=siz[v];
        }
        siz[u]++;
        for(int i=0;i<=n;i++){
            if(i==a[u])dp[u][i]=(a[u]?cnt[i-1]:0);
            else dp[u][i]=cnt[i];
        }
    };
    f(1,0);
    int ans=0;
    for(int i=0;i<=n;i++){
        ans+=dp[1][i];
        ans%=mod;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}