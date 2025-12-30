#include<bits/stdc++.h>
using namespace std;

//1,10;
//1,1¡£2£¬3¡£3£¬4¡£4£¬5¡£5£¬6¡£6£¬7¡£7£¬8¡£ 
void solve(){
	int l,r;
	cin>>l>>r;
	if(l==r){
		if(l==1)cout<<1<<endl;
		else	cout<<0<<endl;
	} 
	else{
		cout<<r-l<<endl;
	}
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
