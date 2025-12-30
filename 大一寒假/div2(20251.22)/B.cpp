#include<bits/stdc++.h>
#define int long long
using namespace std;

struct mp{
	int k,p;
};
const int maxn=1e5+50;
int a[maxn];
mp b[maxn];
bool f1[maxn],f2[maxn];
bool cmp(mp a,mp b){
	return a.k==b.k?a.p<b.p:a.k<b.k;
}
void solve(){
	int n,l,r;
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].k=a[i];
		b[i].p=i;
		f1[i]=0;
		f2[i]=0;
	}
	sort(a+1+l,a+1+r);
	sort(b+1,b+1+n,cmp);
	int ans1=0,ans2=0;
	for(int i=r;i>=l;i--){
		int j=1;
		while(b[j].k<a[i]){
			if(!f1[b[j].p]){
				if(b[j].p>r){
					ans1+=b[j].k;
					f1[b[j].p]=1;
					break;
				}
				else	j++;
			}else{
				j++;
			}
		}
		if(b[j].k>=a[i])ans1+=a[i];
	}
	for(int i=r;i>=l;i--){
		int j=1;
		while(b[j].k<a[i]){
			if(!f2[b[j].p]){
				if(b[j].p<l){
					ans2+=b[j].k;
					f2[b[j].p]=1;
					break;
				}
				else	j++;
			}else{
				j++;
			}
		}
		if(b[j].k>=a[i])ans2+=a[i];
	}
	cout<<min(ans1,ans2)<<endl;
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
