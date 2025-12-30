#include<bits/stdc++.h>
using namespace std;

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int a1=2*b-c,b1=a+c,c1=2*b-a;
	if((a1>0&&a1%a==0)||(b1>0&&b1%(2*b)==0)||(c1>0&&c1%c==0))cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
