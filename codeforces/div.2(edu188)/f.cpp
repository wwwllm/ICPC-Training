#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int exp(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int inv(int x)
{
    return exp(x,mod-2);
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<array<int,2>>b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i][0],b[i][1]=i;
    ranges::sort(b);
    vector<int>stk;
    vector<int>r(n,n),l(n,-1);
    for(int i=0;i<n;i++){
        while(stk.size()&&a[stk.back()]>=a[i]){
            stk.pop_back();
        }
        if(stk.size()){
            l[i]=stk.back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for(int i=n-1;i>=0;i--){
        while(stk.size()&&a[stk.back()]>a[i]){
            stk.pop_back();
        }
        if(stk.size()){
            r[i]=stk.back();
        }
        stk.push_back(i);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        int cnt=i*(n-i+1)%mod;
        sum+=cnt*inv(a[i])%mod;
        sum%=mod;
    }
    vector<array<int,2>>cnt;
    for(int i=0;i<n;i++){
        cnt.push_back({a[i],(i-l[i])*(r[i]-i)%mod});
    }
    ranges::sort(cnt);
    auto f=[&](int x,int k){
        if(x>k){
            return k*inv(x)%mod;
        }
        else{
            return (k-x+2-inv(x)+mod)%mod;
        }
    };
    int sum0=0,sum1=0,sumr=0;
    for(auto [v,c]:cnt){
        sum0+=c*inv(v)%mod;
        sum0%=mod;
    }
    int p=0;
    for(int i=0;i<m;i++){
        auto [k,idx]=b[i];
        while(p<cnt.size()&&cnt[i][0]<=k){
            auto [val,c]=cnt[p];
            sum0-=c*inv(val)%mod;
            sum0=(sum0+mod)%mod;
            sum1+=c;
            sum1%=mod;
            int r=(2-val-inv(val)%mod+2*mod)%mod;
            sumr+=c*r%mod;
            sumr%=mod;
            p++;
        }
        int ans=sum;
        ans+=(k*sum0%mod+k*sum1%mod+sumr)%mod;
        ans%=mod;
        cout<<ans<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio,cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}