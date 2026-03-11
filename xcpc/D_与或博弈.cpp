#include<bits/stdc++.h>
#define int long long
using namespace std;

//https://codeforces.com/gym/105992/problem/D
void solve(){
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    bool ok=1;
    if(a==x){
        for(int i=61;i>=0;i--){
            if(((b>>i)&1)==1&&((y>>i)&1)==0)ok=0;
        }
    }
    else if(b==y){
        for(int i=61;i>=0;i--){
            if(((a>>i)&1)==0&&((x>>i)&1)==1)ok=0;
        }
    }
    else ok=0;
    cout<<(ok?"Yes\n":"No\n");
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}