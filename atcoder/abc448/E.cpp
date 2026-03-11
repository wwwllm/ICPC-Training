#include<bits/stdc++.h>
#define int long long
using namespace std;

int exp(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void solve(){
    int m,k;
    cin>>k>>m;
    int mod=m*10007;
    vector<array<int,2>>a(k);
    for(int i=0;i<k;i++)cin>>a[i][0]>>a[i][1];
    unordered_map<int,int>mp;
    function<int(int)> calc=[&](int len){
        if(mp.count(len))return mp[len];
        if(len==1)return mp[len]=1LL;
        if(len&1){
            return mp[len]=(calc(len-1)*10%mod+1)%mod;
        }
        else{
            return mp[len]=(calc(len/2)*exp(10,len/2,mod)+calc(len/2))%mod;
        }
    };
    int ans=0;
    for(auto [x,len]:a){
        ans=ans*exp(10,len,mod)%mod+x*calc(len)%mod;
        ans%=mod;
    }
    cout<<ans/m<<'\n';
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}