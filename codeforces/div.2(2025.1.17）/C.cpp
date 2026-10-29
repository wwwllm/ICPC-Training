#include<bits/stdc++.h>
using namespace std;

//111  121
//1111 1221 

//6:121312
//7:1213123
//8:12131232
//
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n-2;i++){
		cout<<i<<' ';
	}
	cout<<1<<' '<<1<<endl;
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
