#include<bits/stdc++.h>
using namespace std;

int n,b[20]={0};
double sum=0,mind=100000000000,juli[20][20];
struct dian{
	double x=0,y=0;
}t[20];
double d(dian a,dian b){
	double len=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return len;
}
void dfs(int k,int i){ 
	if(k>=n){
		mind=min(sum,mind);
		return ;
	}
	if(i>n)return ;
	for(int j=1;j<=n;j++){
		if(b[j]==0){
			double len=juli[i][j];
			if(sum+len>mind)continue;
			sum+=len;
			b[j]=1;
			dfs(k+1,j);
			sum-=len;
			b[j]=0;
		}	
	}	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].x>>t[i].y;
	} 
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			juli[i][j]=d(t[i],t[j]);
			juli[j][i]=juli[i][j];
		}
	}
	dfs(0,0);
	cout<<fixed<<setprecision(2)<<mind;
	return 0;
} 
