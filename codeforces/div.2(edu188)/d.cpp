#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector adj(n+1,vector<int>());
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,-1);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]!=-1)continue;
        queue<int>q;
        q.push(i);
        vis[i]=0;
        int cnt1=0,cnt0=0;
        bool ok=1;
        while(q.size()){
            int u=q.front();
            q.pop();
            if(vis[u]==1)cnt1++;
            else cnt0++;
            for(auto v:adj[u]){
                if(vis[v]==-1){
                    vis[v]=!vis[u];
                    q.push(v);
                }
                else{
                    if(vis[v]==vis[u])ok=0;
                }
            }
            
        }
        if(ok){
            ans+=max(cnt1,cnt0);
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}