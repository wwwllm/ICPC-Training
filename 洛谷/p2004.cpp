#include<bits/stdc++.h>
#define int long long
using namespace std;

//×¢ÒâÓÃlong long 
const int maxn=1050;
int f[maxn][maxn]={{0}};
signed main(){
	int n,m,c,temp;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>temp;
			f[i][j]=f[i][j-1]+f[i-1][j]-f[i-1][j-1]+temp;
		}
	}
	int ans=-1000000,x,y;
	for(int i=1;i<=n-c+1;i++){
		for(int j=1;j<=m-c+1;j++){
			int sum=f[i+c-1][j+c-1]+f[i-1][j-1]-f[i-1][j+c-1]-f[i+c-1][j-1];
			if(sum>ans){
				ans=sum;
				x=i,y=j;
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
