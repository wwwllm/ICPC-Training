#include<bits/stdc++.h>
#define int long long
using namespace std;

struct mp{
	int k,p;
};
const int maxn=2e5+50;
int a[maxn],b[maxn]; 
mp da[maxn],db[maxn];
bool cmp(mp a,mp b){
	return a.k!=b.k?a.k<b.k:a.p<b.p;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)da[i].k=a[i]-a[i-1],da[i].p=i;
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++)db[i].k=b[i]-b[i-1],db[i].p=i;
	sort(da+1,da+1+n,cmp);
	sort(db+1,db+1+n,cmp);
	
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
