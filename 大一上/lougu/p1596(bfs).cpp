#include<bits/stdc++.h>
using namespace std;

int walk[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
struct dian{
	int x,y;
};
int n,m;
char p[105][105];
queue<dian> Q;
int b[105][105];
int main(){
	cin>>n>>m;
	int num=0;
	memset(b,-1,sizeof(b));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[i][j]=='W'&&b[i][j]==-1){
				b[i][j]=1;
				dian q={i,j};
				Q.push(q);
				while(!Q.empty()){
					dian s=Q.front();
					Q.pop();
					for(int i=0;i<8;i++){
						if(p[s.x+walk[i][0]][s.y+walk[i][1]]=='W'&&b[s.x+walk[i][0]][s.y+walk[i][1]]==-1){
							dian o={s.x+walk[i][0],s.y+walk[i][1]};
							Q.push(o);
							b[s.x+walk[i][0]][s.y+walk[i][1]]=1;
						}
					}
				}
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
