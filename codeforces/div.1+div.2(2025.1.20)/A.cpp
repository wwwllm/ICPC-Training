#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++)cin>>a[i];
	bool flag=false;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]%2==0)flag=true;
		else	ans++;
	}
	if(flag)ans++;
	else	ans--;
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
