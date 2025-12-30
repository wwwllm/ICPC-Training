#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+50;
struct cost{
	int a,b,c;
};
int p[maxn],num[maxn]={0};
cost f[maxn];
signed main(){
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>p[i];
	for(int i=1;i<m;i++){
		int x,y;
		x=max(p[i],p[i+1]);
		y=min(p[i],p[i+1]);
		num[x]--;
		num[y]++;
	}
	for(int i=1;i<=n-1;i++){
		num[i]+=num[i-1];
	}
	for(int i=1;i<=n-1;i++){
		cin>>f[i].a>>f[i].b>>f[i].c;
	}
	for(int i=1;i<=n-1;i++){
		int costa,costb;
		costa=num[i]*f[i].a;
		costb=num[i]*f[i].b+f[i].c;
		ans+=min(costa,costb);
	}
	cout<<ans<<endl;
	return 0;
}
