#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int a,b,d,e;
	cin>>a>>b>>d>>e;
	int c1=a+b,c2=d-b,c3=e-d;
	if(c1!=c2&&c2!=c3&&c1!=c3)cout<<1<<endl;
	else{
		if(c1==c2&&c2==c3)cout<<3<<endl;
		else	cout<<2<<endl;
	} 
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
