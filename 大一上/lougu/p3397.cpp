#include<bits/stdc++.h>
using namespace std;

//¶þÎ¬²î·Ö£º 
// df[x][y]=f[x][y]+f[x-1][y-1]-f[x][y-1]-f[x-1][y] 
const int maxn=1005;
int df[maxn][maxn];
int n,m;
int main(){
	cin>>n>>m;
	while(m--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		df[x1][y1]++;
		df[x1][y2+1]--;
		df[x2+1][y1]--;
		df[x2+1][y2+1]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			df[i][j]-=df[i-1][j-1]-df[i][j-1]-df[i-1][j];
			cout<<df[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
} 
