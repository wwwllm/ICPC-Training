#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+50;
int a[maxn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n-1;i++){
		int minn=min(a[i],a[i+1]);
		a[i]-=minn,a[i+1]-=minn;
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1]){cout<<"No\n";return;}
	}
	cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
