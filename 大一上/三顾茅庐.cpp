#include<bits/stdc++.h>
using namespace std;

int q;
long long x,y,k,ans;
void solve(){
	cin>>x>>y>>k;
	if(y==0){
		ans=x;
		return ;
	}
	if(x-y*k>=0)ans=x-y*k;
	else{
		int t=k-x/y;
		x%=y;
		if(t%2==0)	ans=x;
		else	ans=y-x;
	}
}
int main(){
	cin>>q;
	while(q--){
		solve();
		cout<<ans<<endl;	
	}
	return 0;
} 
