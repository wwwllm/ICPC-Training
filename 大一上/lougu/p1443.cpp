#include<bits/stdc++.h>
using namespace std;

#define maxn 310
struct dian{
	int x,y;
};
queue<dian> Q;
int t[maxn][maxn];
int walk[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int main(){
	memset(t,-1,sizeof(t));
	int n,m,sx,sy;
	cin>>n>>m>>sx>>sy;
	dian d0={sx,sy};
	Q.push(d0);
	t[d0.x][d0.y]=0;
	while(!Q.empty()){
		dian p=Q.front();
		Q.pop();
		int px=p.x,py=p.y;
		for(int i=0;i<8;i++){
			int x=px+walk[i][0],y=py+walk[i][1];
			int d=t[px][py];
			if(x<1||x>n||y<1||y>m||t[x][y]!=-1)continue;
			t[x][y]=d+1;
			dian tmp={x,y};
			Q.push(tmp);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<t[i][j]<<'\t';
		}
		cout<<endl;
	}
	return 0;
}
