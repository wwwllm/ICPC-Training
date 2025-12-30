#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e6+50;
int n,m;
int r[maxn],d[maxn],s[maxn],t[maxn],ans[maxn];
bool f(int k){
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=k;i++){
		ans[s[i]]+=d[i];
		ans[t[i]+1]-=d[i];
	}
	for(int i=1;i<=n;i++){
		ans[i]+=ans[i-1];
		if(r[i]<ans[i])return false;
	} 
	return true;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>r[i];
	for(int i=1;i<=m;i++)cin>>d[i]>>s[i]>>t[i];
	if(f(m)){
		cout<<0<<endl;
		return 0;
	}
	cout<<-1<<endl;
	int l=0,r=m+1,mid;
	while(l+1!=r){
		mid=(l+r)>>1;
		if(f(mid))l=mid;
		else	r=mid;
	}
	cout<<r<<endl;
	return 0;
}
