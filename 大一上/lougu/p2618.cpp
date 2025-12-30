#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+50;
int vis[maxn],n[maxn][25],ans[maxn],p[maxn]={0};//prime[maxn],t=0;//p存储素因数个数，n存储每个数的素因数，prime存储素数 
void solve(){
	for(int i=2;i<=maxn;i++){
		/*if(!vis[i]){
			prime[++t]=i;
			n[i][++p[i]]=i;
		}
		for(int j=1;j<=t&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			n[i*prime[j]][++p[i*prime[j]]]=prime[j];
			if(!vis[i]&&j!=t)n[i*prime[j]][++p[i*prime[j]]]=i;
		}*/
		if(!vis[i])
			for(int j=i;j<=maxn;j+=i)
				vis[j]=1,n[j][++p[j]]=i;	
	}
	ans[1]=0;
	for(int i=2;i<=maxn;i++){
		ans[i]=ans[i-1]+1;
		for(int j=1;j<=p[i];j++)ans[i]=min(ans[i],ans[i/n[i][j]]+1);
	}
}
int main(){
	int n;
	solve();
	while(cin>>n){
		cout<<ans[n]<<endl;
	}
	return 0;
}

