#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+50;
int a[maxn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int c=0,b=0;
	for(int i=1;i<=n;i++){
		if(a[i]>i)b+=a[i]-i;
		else	c+=i-a[i]; 
	}
	if(c==b)cout<<c<<endl;
	else	cout<<-1<<endl;
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
