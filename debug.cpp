#include<bits/stdc++.h>
#define EL puts("Elaina")
typedef long long ll;
using namespace std;
const int maxn=3e5+5,block=600;
int n,k,Q,c[maxn],cnt[maxn];ll ans[maxn];
array<int,26> a[maxn],b[maxn];
char s[maxn];
struct query{
	int l,r,id;
	bool operator <(const query &a)const{
		int i=l/block,j=a.l/block;
		return i!=j?i<j:i&1?a.r<r:r<a.r;
	}
}q[maxn];
inline void MyDearMoments(){
	scanf("%d%d%d%s",&n,&k,&Q,s+1);
	for(int i=1;i<=n;++i)a[i]=a[i-1],(++a[i][s[i]-'a'])%=k,b[i]=a[i];
	sort(b,b+n+1);int m=unique(b,b+n+1)-b-1;
	for(int i=0;i<=n;++i)c[i]=lower_bound(b,b+m+1,a[i])-b;
	for(int i=1;i<=Q;++i)scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,q[i].id=i;
	sort(q+1,q+Q+1);
	int l=0,r=-1;ll tmp=0;
	for(int i=1;i<=Q;++i){
		while(r<q[i].r)tmp+=cnt[c[++r]]++;
		while(l>q[i].l)tmp+=cnt[c[--l]]++;
		while(l<q[i].l)tmp-=--cnt[c[l++]];
		while(r>q[i].r)tmp-=--cnt[c[r--]];
		ans[q[i].id]=tmp;
	}
	for(int i=1;i<=Q;++i)printf("%lld\n",ans[i]);
}
int main(){return MyDearMoments(),0;}