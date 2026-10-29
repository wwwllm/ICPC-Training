#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int maxn=200010;
struct ks{
	ll w,v;
}; 
ks a[maxn];
ll sumw[maxn],sumv[maxn],l[maxn],r[maxn];
ll n,m;
ll rw,lw=0,mid,s,num,ans;
int main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin>>n>>m>>s;
	ans=s;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].v;
		if(a[i].w>rw)rw=a[i].w;		
	}
	rw++;
	for(int i=1;i<=m;i++)cin>>l[i]>>r[i];
	while(lw+1!=rw){
		mid=(lw+rw)>>1;
		num=0;
		memset(sumw,0,sizeof(sumw));
		memset(sumv,0,sizeof(sumv));
		for(int i=1;i<=n;i++){
			if(mid<=a[i].w){
				sumw[i]=sumw[i-1]+1;
				sumv[i]=sumv[i-1]+a[i].v;
			}else{
				sumw[i]=sumw[i-1];
				sumv[i]=sumv[i-1];
			}
		}
		for(int i=1;i<=m;i++){
			num+=(ll)(sumw[r[i]]-sumw[l[i]-1])*(sumv[r[i]]-sumv[l[i]-1]);
		}
		ans=min(ans,abs(num-s));
		if(num>s){
			lw=mid;
		}else if(num<s){
			rw=mid;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
