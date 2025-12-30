#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+50;
int du[maxn];
void solve(){
	memset(du,0,sizeof(du));
	int n;
	cin>>n;
	int l,r,ans[3],top=0;
	for(int i=1;i<=n-1;i++){
		cin>>l>>r;
		du[l]++,du[r]++;
	}
	for(int i=1;i<=n;i++){
		if(du[i]==1){
			if(top<=1)	ans[top++]=i;
			else	{
				cout<<-1<<endl;
				return ;
			}
		}
	}
	cout<<ans[0]<<' '<<ans[1]<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
