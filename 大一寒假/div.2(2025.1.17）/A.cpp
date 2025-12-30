#include<bits/stdc++.h>
using namespace std;

const int maxn=105;
int x[105],y[105];
void solve(){
	int n,m;
	cin>>n>>m;
	int c=4*m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		x[i]+=x[i-1];
	}
	for(int i=1;i<=n;i++){
		cin>>y[i];
		y[i]+=y[i-1];
	}
	int ans=n*c;
	for(int i=2;i<=n;i++){
		if(x[i]<x[i-1]+m&&y[i]<y[i-1]+m){
			ans-=x[i-1]+m+y[i]<y[i-1]+m-x[i]-y[i];
		}
	}
	cout<<ans<<endl;
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
