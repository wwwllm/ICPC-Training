#include<bits/stdc++.h>
#define int long long
using namespace std;

//https://codeforces.com/gym/105911/problem/I
const int N=2e5,mod=998244353;
vector<int>p(N+1),ivp(N+1);
int exp(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int inv(int x){
    return exp(x,mod-2);
}
void init(){
    p[0]=ivp[0]=1;
    for(int i=1;i<=N;i++){
        p[i]=p[i-1]*i%mod;
    }
    ivp[N]=inv(p[N]);
    for(int i=N-1;i>=1;i--){
        ivp[i]=ivp[i+1]*(i+1)%mod;
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    auto C=[&](int n,int m)->int{
        if(n<0||m>n)return 0;
        return p[n]*ivp[m]%mod*ivp[n-m]%mod;
    };
    string s;
    cin>>s;
    vector<int>pos;
    pos.push_back(0);
    for(int i=0;i<n;i++){
        if(s[i]=='1')pos.push_back(i+1);
    }
    int m=pos.size();
    pos.push_back(n+1);
    if(m<k){
        cout<<0<<'\n';
        return ;
    }
    int ans=0;
    for(int i=k;i<m;i++){
        if(i==m-1)ans=(ans+C(pos[i+1]-pos[i-k]-1,k))%mod;
        else    ans=(ans+C(pos[i+1]-pos[i-k]-1,k)-C(pos[i+1]-pos[i-k+1]-1,k-1)+mod)%mod;

    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    init();
    while(t--)
        solve();
    return 0;
}