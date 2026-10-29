#include<bits/stdc++.h>
using namespace std;

int b[7]={0};
void solve(){
	int a;
	bool flag=1;
	for(int i=1;i<=7;i++){
		cin>>a;
		if(a==4||a==7)flag=0;
	}
	if(flag)cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;
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
