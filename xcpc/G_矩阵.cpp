#include<bits/stdc++.h>
using namespace std;

//https://codeforces.com/gym/105992/problem/G
void solve(){
    int n;
    cin>>n;
    // vector<int>prime;
    // vector<int>vis(n+1);
    // vis[0]=vis[1]=1;
    // for(int i=2;i<=n;i++){
    //     if(vis[i]==0)prime.push_back(i);
    //     for(int j=0;prime[j]<=n/i;j++){
    //         vis[prime[j]*i]=1;
    //         if(i%prime[j]==0)break;
    //     }
    // }
    // for(auto x:prime)cout<<x<<' ';
    // cout<<'\n';
    auto check=[&](int x){
        for(int i=2;i<=x/i;i++){
            if(x%i==0)return 0;
        }
        return 1;
    };
    int p=n+1;
    for(;;p++){
        if(check(p))break;
    }
    vector ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=i+1+(j+1)*p;
        }
    }
    for(auto a:ans){
        for(auto x:a)cout<<x<<' ';
        cout<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    solve();
    return 0;
}