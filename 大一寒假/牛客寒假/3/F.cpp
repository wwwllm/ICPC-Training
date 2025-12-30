#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(a+b+c<n){
		cout<<"No"<<endl;
		return ;
	}
	if(a+b+c>2*n){
		cout<<"No"<<endl;
		return ;
	}
	cout<<"Yes"<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
