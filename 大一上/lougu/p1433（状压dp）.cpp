#include<bits/stdc++.h>
using namespace std;

double len[20][20],f[20][50000];
struct dian{
	double x=0,y=0;
}t[20];
double d(dian a,dian b){
	double len=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return len;
}
int main(){
	int n;
	cin>>n;
	memset(f,127,sizeof(f));
	double ans=f[0][0];
	for(int i=1;i<=n;i++){
		cin>>t[i].x>>t[i].y;
	} 
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			len[i][j]=d(t[i],t[j]);
			len[j][i]=len[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		f[i][1<<(i-1)]=len[0][i];
	}
	for(int l=1;l<(1<<n);l++){//l表示当前状态 
		for(int i=1;i<=n;i++){ 
			if((l&(1<<(i-1)))==0){//如果当前状态为走到i 
			continue; 
			}
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if((l&(1<<(j-1)))==0)continue;
				f[i][l]=min(f[j][l-(1<<(i-1))]+len[i][j],f[i][l]);
			}
		} 
	}
	for(int i=1;i<=n;i++){
		ans=min(ans,f[i][(1<<n)-1]);
	}
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
