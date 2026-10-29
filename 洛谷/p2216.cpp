#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

int a,b,n;
int f[maxn][maxn],q[maxn];
int rowmax[maxn][maxn],rowmin[maxn][maxn],colmax[maxn][maxn],colmin[maxn][maxn];
int ans=1000000000;
int main(){
	cin>>a>>b>>n;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			cin>>f[i][j];
		}
	}
	for(int row=1;row<=a;row++){
		int h=0,t=0;
		for(int i=1;i<=b;i++){//最大值 
			while(h<t&&q[h]+n<=i)	h++;
			while(h<t&&f[row][q[t-1]]<f[row][i])	t--;
			q[t++]=i;
			if(i>=n){
				rowmax[row][i-n+1]=f[row][q[h]];
			}
		}
		h=0,t=0;
		for(int i=1;i<=b;i++){//最大值 
			while(h<t&&q[h]+n<=i)	h++;
			while(h<t&&f[row][q[t-1]]>f[row][i])	t--;
			q[t++]=i;
			if(i>=n){
				rowmin[row][i-n+1]=f[row][q[h]];
			}
		}
	}
	for(int col=1;col<=b-n+1;col++){
		int h=0,t=0;
		for(int i=1;i<=a;i++){
			while(h<t&&q[h]+n<=i)	h++;
			while(h<t&&rowmax[q[t-1]][col]<rowmax[i][col])	t--;
			q[t++]=i;
			if(i>=n){
				colmax[i-n+1][col]=rowmax[q[h]][col];
			}
		}
		h=0,t=0;
		for(int i=1;i<=a;i++){
			while(h<t&&q[h]+n<=i)	h++;
			while(h<t&&rowmin[q[t-1]][col]>rowmin[i][col])	t--;
			q[t++]=i;
			if(i>=n){
				colmin[i-n+1][col]=rowmin[q[h]][col];
			}
		}
	}
	for(int i=1;i<=a-n+1;i++){
		for(int j=1;j<=b-n+1;j++){
			if(colmax[i][j]-colmin[i][j]<ans){
				ans=colmax[i][j]-colmin[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
