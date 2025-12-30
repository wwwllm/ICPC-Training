#include<bits/stdc++.h>
using namespace std;

const int maxn=1e9+50;
int a[maxn];
void solve(){
	int n;
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)	flag=1;
	}	
	if(flag)cout<<-1<<endl;
	else	cout<<10000000019<<endl;
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
