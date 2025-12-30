#include<bits/stdc++.h>
#define maxn 5005
using namespace std;

int n,m[maxn],f[maxn][maxn],ans=0;//f[l][r]表示[l,r]区间内的最小值 
double k(int x,int r){//x点到r点的斜率 
	return (double)(m[r]-m[x])/(r-x);
}
bool check(int l,int x,int r){//x为r现在最左边可以看到的点，l为检查点
	return k(x,r)>k(l,r);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int r=1;r<=n;r++){
		f[r][r]=1;
		ans^=f[r][r];
		int sum=1,p=0;
		for(int l=r-1;l>=1;l--){
			if(p==0||check(l,p,r))sum+=min(f[l+1][p],f[l+1][p-1]),p=l;
			ans^=(f[l][r]=sum+min(f[l][p-1],f[l][p]));
		}
	} 
	cout<<ans<<endl; 
	return 0;
}
