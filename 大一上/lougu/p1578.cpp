#include<bits/stdc++.h>
using namespace std;

struct dian{
	int x,y;
};
const int maxn=30005;
int l,m,n;
int s[maxn],top,t[maxn]={0},ans;
dian p[maxn];
bool cmp(dian a,dian b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
void solve(){//单调栈求以第x行为底的最大矩形 
	top=0;
	s[top++]=0;
	for(int i=1;i<m;i++){
		while(top>0&&t[s[top-1]]>=t[i]){
			if(top>1)ans=max(ans,t[s[top-1]]*(i-s[top-2]));
			else	ans=max(ans,t[s[top-1]]*(i+1));
			top--;
		}
		s[top++]=i;
	}
	while(top!=0){
		if(top>1)ans=max(ans,t[s[--top]]*(m-s[top-1]-1));
		else	ans=max(ans,t[s[--top]]*m);
	}
}
int main(){
	cin>>l>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
	}
	sort(p+1,p+1+n,cmp);
	int q=1; 
	for(int i=0;i<l;i++){
		while(q!=n+1){//找x=i的障碍 
			if(p[q].x==i)t[p[q].y]=-1;
			else	break;
			q++;
		}
		for(int j=0;j<m;j++)t[j]++;
		solve();
	}
	cout<<ans;
	return 0;
}
