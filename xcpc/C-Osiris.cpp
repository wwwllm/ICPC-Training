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
int inv(int x){
    return exp(x,mod-2);
}
void solve(){
    vector<int>a;
    vector<int>cnt(14,4);
    int sum=0;
    for(int i=0;i<5;i++){
        string c;
        cin>>c;
        int val=0;
        if(c=="A")val=1;
        else if(c=="J")val=11;
        else if(c=="Q")val=12;
        else if(c=="K")val=13;
        else if(c=="10")val=10;
        else val=c[0]-'0';
        sum+=val;
        a.push_back(val);
        cnt[val]--;
    }
    sort(a.begin(),a.end());
    vector dp(6,vector<vector<vector<int>>>(6,vector<vector<int>>(100,vector<int>(100,0))));
    dp[0][0][0][0]=1;
    for(int i=1;i<14;i++){
        for(int c=0;c<cnt[i];c++){
            for(int k=5;k>=0;k--){
                for(int j=5;j>=0;j--){
                    for(int sk=99;sk>=0;sk--){
                        for(int sj=99;sj>=0;sj--){
                         if(sk>=i&&k)dp[k][j][sk][sj]=(dp[k-1][j][sk-i][sj]+dp[k][j][sk][sj])%mod;
                         if(sj>=i&&j)dp[k][j][sk][sj]=(dp[k][j-1][sk][sj-i]+dp[k][j][sk][sj])%mod;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=5;i++){
        sum-=a[i-1];
        int r=sum;
        int q=0;
        int ans=0;
        for(int sk=0;sk<100;sk++){
            for(int sj=0;sj<100;sj++){
                q+=dp[i][5][sk][sj];
                q%=mod;
                if(r+sk==sj)continue;
                ans+=(r+sk>sj?i:-i)*dp[i][5][sk][sj]%mod;
                ans=(ans+mod)%mod;
            }
        }
        cout<<ans*inv(q)%mod<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}