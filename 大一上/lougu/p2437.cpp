
#include<bits/stdc++.h>
using namespace std;

int f[1050][1001]={0},len=1;
int main(){
	int n,m;
	cin>>m>>n;
	f[1][1]=1;
	f[2][1]=1;
	for(int i=3;i<=n-m+1;i++){
		for(int j=1;j<=len;j++)
			f[i][j]=f[i-1][j]+f[i-2][j];
		for(int j=1;j<=len;j++){
			if(f[i][j]>9){
				f[i][j+1]+=f[i][j]/10;
				f[i][j]%=10;
			}
		}
		if(f[i][len+1]!=0)len++;	
	}
	for(int i=len;i>=1;i--){
		cout<<f[n-m+1][i];
	}
	return 0;
} 

