#include<bits/stdc++.h>
using namespace std;

int n,m,p[15][15],x[15],y[15],sx,sy,fx,fy,ans=0;
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return ;
	}
	p[x][y]=2;
	if(x>1&&p[x-1][y]!=1&&p[x-1][y]!=2)dfs(x-1,y);
	if(x<n&&p[x+1][y]!=1&&p[x+1][y]!=2)dfs(x+1,y);
	if(y<m&&p[x][y+1]!=1&&p[x][y+1]!=2)dfs(x,y+1);
	if(y>1&&p[x][y-1]!=1&&p[x][y-1]!=2)dfs(x,y-1);
	p[x][y]=0;
}
int main(){
	int t;cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	for(int i=1;i<=t;i++){
		cin>>x[i]>>y[i];
		p[x[i]][y[i]]=1;
	}
	dfs(sx,sy);
	cout<<ans;
	return 0;
}
