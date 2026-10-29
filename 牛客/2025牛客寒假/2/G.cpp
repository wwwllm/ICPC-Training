#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	ll ans=1,Min=abs(n-m),t=m;
	for(int i=2;i<=32;i++){
		if(t>1e18/m)break;
		t*=m;
		if (abs(n - t) < Min) {
            Min = abs(n - t);
            ans = i;
        }
	}
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
