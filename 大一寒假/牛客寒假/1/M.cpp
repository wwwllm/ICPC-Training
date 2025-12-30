#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+50;
struct mp{
	int k,p;
};
mp a[maxn];
int b[maxn]={0};
bool cmp(mp a,mp b){
	if(a.k!=b.k)return a.k<b.k;
	return a.p<b.p;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		a[i].p=i;
		b[i]=a[i].k;
	}
	sort(a+1,a+1+n,cmp);
	a[n+1].k=2e9;
	int l=a[1].p,r=a[1].p;
	int ma=max(a[1].k*2,a[n].k);
	int ans=ma-min(a[1].k*2,a[2].k);
	for(int i=2;i<=n;i++){
		while(a[i].p<l){
			l--;
			ma=max(ma,b[l]*2);
		}
		while(a[i].p>r){
			r++;
			ma=max(ma,b[r]*2);
		}
		ans=min(ans,ma-min(a[1].k*2,a[i+1].k));
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
