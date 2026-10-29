#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+50;
int a[maxn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int mid;
	if(n%2==1)mid=(n+1)>>1;
	else	mid=n/2+1;
	cout<<a[mid]-1;
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
