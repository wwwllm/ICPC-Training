#include<bits/stdc++.h>
using namespace std;

int n;
int walk[8][2]={{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1},{0,1},{0,-1}};
int p[101][101]={{0}};
char t[101][101],key[8]="yizhong";
bool dfs(int x,int y,int k,int l){
	if(k==7){
		p[x][y]=1;
		return true;
	}
	if(l==-1){
		for(int i=0;i<8;i++){
			if((x+walk[i][0]>=1)&&(x+walk[i][0]<=n)&&(y+walk[i][1]>=1)&&(y+walk[i][1]<=n)){
				if(t[x+walk[i][0]][y+walk[i][1]]==key[k]){
					if(dfs(x+walk[i][0],y+walk[i][1],k+1,i)){
						p[x][y]=1;
						return true;
					}
				}
			}
		}
	}
	else{
		if((x+walk[l][0]>=1)&&(x+walk[l][0]<=n)&&(y+walk[l][1]>=1)&&(y+walk[l][1]<=n)){
				if(t[x+walk[l][0]][y+walk[l][1]]==key[k]){
					if(dfs(x+walk[l][0],y+walk[l][1],k+1,l)){
						p[x][y]=1;
						return true;
					}
				}
			}
	}
	return false;
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>t[i][j]; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(t[i][j]=='y') {
				dfs(i,j,1,-1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(p[i][j]==0){
				cout<<'*';
			}else{
				cout<<t[i][j];
			}
		}
		cout<<endl;
	}
	return 0;
}
