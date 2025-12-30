#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353,maxn=2e5+50;
int a[maxn],dp[maxn][2]={{0}};//0ÎªÕæ£¬1Îª¼Ù 
void solve(){
	memset(dp,0,sizeof(dp));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dp[1][0]=a[1]==0,dp[1][1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])dp[i][0]+=dp[i-1][0],dp[i][0]%=mod;
		dp[i][1]+=dp[i-1][0],dp[i][1]%=mod;
		if(a[i]==a[i-2]+1)dp[i][0]+=dp[i-1][1],dp[i][0]%=mod;
	}
	cout<<(dp[n][0]+dp[n][1])%mod<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
