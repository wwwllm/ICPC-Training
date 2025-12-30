#include<bits/stdc++.h>
#define int long long
using namespace std;

struct dian{int x,y;
};
bool cmp(dian a,dian b){
	return a.x<b.x;
}
const int maxn=100050;
int n,d,ans=1000000000;
dian p[maxn];
int qmax[maxn],hmax=0,tmax=0;
int qmin[maxn],hmin=0,tmin=0;
bool check(){
	int maxi=hmax<tmax?p[qmax[hmax]].y:0;
	int mini=hmin<tmin?p[qmin[hmin]].y:0;
	return maxi-mini>=d;
}
void push(int r){
	while(hmax<tmax&&p[qmax[tmax-1]].y<=p[r].y)tmax--;
	qmax[tmax++]=r;
	while(hmin<tmin&&p[qmin[tmin-1]].y>=p[r].y)tmin--;
	qmin[tmin++]=r;
}
void pop(int l){
	while(hmax<tmax&&qmax[hmax]==l)hmax++;
	while(hmin<tmin&&qmin[hmin]==l)hmin++;
}
signed main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	sort(p+1,p+1+n,cmp);
	for(int l=1,r=1;l<=n;l++){
		while(r<=n&&!check())push(r++);
		if(check())ans=min(ans,p[r-1].x-p[l].x),flag=true;
		pop(l);
	}
	if(flag)cout<<ans<<endl;
	else	cout<<-1<<endl;
	return 0;
}

