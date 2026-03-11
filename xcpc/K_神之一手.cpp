#include<bits/stdc++.h>
#define int long long
using namespace std;

//https://codeforces.com/gym/105992/problem/K
const int mod=1e9+7;
int exp(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int inv (int x){return exp(x,mod-2);};
void solve(){
    int p,q,r;
    cin>>p>>q>>r;
    int inv1000=inv(1000);
    p=p*inv1000%mod;
    q=q*inv1000%mod;
    r=r*inv1000%mod;
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector dp(n+1,array<int,2>());
    dp[0][0]=1;
    vector<int>ans(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        ans[i]+=dp[i-1][1]*r%mod;
        ans[i]%=mod;
        int x=min({80-sum,a[i]});
        x=max(x,0LL);
        int px=(1-p+mod)%mod*(1-q+mod)%mod;
        px=(1-px+mod)%mod;
        int y=a[i]-x;
        swap(x,y);
        int py=p;
        int p0=exp((1-py+mod)%mod,y)*exp((1-px+mod)%mod,x)%mod;
        int tmp1 = (y % mod) * py % mod * exp((1 - py + mod) % mod, max(0LL, y - 1)) % mod * exp((1 - px + mod) % mod, x) % mod;
        int tmp2 = (x % mod) * px % mod * exp((1 - px + mod) % mod, max(0LL, x - 1)) % mod * exp((1 - py + mod) % mod, y) % mod;
        int p1 = (tmp1 + tmp2) % mod;
    
        int pn = (1 - p1 - p0 + 2 * mod) % mod;
        ans[i]+=dp[i-1][1]*(1-r+mod)%mod*(1-p0+mod)%mod+dp[i-1][0]*pn%mod;
        ans[i]%=mod;
        dp[i][0]=dp[i-1][0]*p0%mod;
        dp[i][1]=dp[i-1][1]*((1-r+mod)%mod)%mod*p0%mod+dp[i-1][0]*p1%mod;
        cout<<ans[i]<<'\n';
        sum+=a[i];
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}