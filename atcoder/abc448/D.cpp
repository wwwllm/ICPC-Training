#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector adj(n+1,vector<int>());
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dp(n+1);
    map<int,int>mp;
    mp[a[1]]++;
    function<void(int,int)> dfs=[&](int u,int f){
        for(auto v:adj[u]){
            if(f==v)continue;
            if(dp[u])
                dp[v]=1;
            else{
                if(mp.count(a[v])&&mp[a[v]]>=1)
                    dp[v]=1;
                else
                    dp[v]=0;
            }
            mp[a[v]]++;
            dfs(v,u);
            mp[a[v]]--;
        }
    };
    dfs(1,0);
    for(int i=1;i<=n;i++){
        cout<<(dp[i]?"Yes\n":"No\n");
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}