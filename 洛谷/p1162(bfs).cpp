#include<bits/stdc++.h>
using namespace std;

struct dian{
	int x,y;
};
int t[35][35],b[35][35]={{0}};
int walk[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n;
queue<dian>Q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
			b[i][j]=t[i][j];
		}
	}
	Q.push((dian){0,0});
	b[0][0]=1;
	while(!Q.empty()){
		dian p=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			if(p.x+walk[i][0]<=n+1&&p.x+walk[i][0]>=0&&p.y+walk[i][1]>=0&&p.y+walk[i][1]<=n+1&&b[p.x+walk[i][0]][p.y+walk[i][1]]==0){
				dian u={p.x+walk[i][0],p.y+walk[i][1]};
				Q.push(u);
				b[p.x+walk[i][0]][p.y+walk[i][1]]=1;
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==0)cout<<2<<' ';
			else	cout<<t[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
