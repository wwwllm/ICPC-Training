#include<bits/stdc++.h>
#define int long long
using namespace std;

//https://codeforces.com/gym/105992/problem/M
using i128=__int128;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    i128 ans=-1;
    for(int i=30;i>=0;i--){
        i128 res=0;
        for(auto z:a)
        {
            res+=(z>>i)*x;
        }
        for(int j=i-1;j>=0;j--){
            int cnt=0;
            for(auto z:a){
                if((z>>j)&1)cnt++;
            }
            res+=x*cnt+y;
        }
        if(ans==-1)ans=res;
        ans=min(ans,res);
    }
    cout<<(int)ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}