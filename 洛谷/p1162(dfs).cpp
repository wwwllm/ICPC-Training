#include<bits/stdc++.h>
using namespace std;

int t[35][35],b[35][35]={{0}};
int walk[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n;
void dfs(int x,int y){
	if(x>n+1||x<0||y>n+1||y<0||b[x][y]!=0)return ;
	b[x][y]=1;
	for(int i=0;i<4;i++){
		dfs(x+walk[i][0],y+walk[i][1]);
	}
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
			b[i][j]=t[i][j];
		}
	}
	dfs(0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==0)cout<<2<<' ';
			else	cout<<t[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
