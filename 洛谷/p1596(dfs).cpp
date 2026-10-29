#include<bits/stdc++.h>
using namespace std;

int walk[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
int n,m;
char p[105][105];
int b[105][105]={{0}};
void dfs(int x,int y,int num){
	for(int i=0;i<8;i++){
		if(((x+walk[i][0]<=n)&&(x+walk[i][0]>=1))&&((y+walk[i][1]<=m)&&(y+walk[i][1]>=1))){
			if(p[x+walk[i][0]][y+walk[i][1]]=='W'&&b[x+walk[i][0]][y+walk[i][1]]!=num){
				b[x+walk[i][0]][y+walk[i][1]]=num;
				dfs(x+walk[i][0],y+walk[i][1],num);
			}
		}
	}
	return ;
}
int main(){
	cin>>n>>m;
	int num=1;
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]=='W'&&b[i][j]==0){
				b[i][j]=num;
				dfs(i,j,num);
				num++;
			}
		}
	}
	cout<<num-1;
	return 0;
}
