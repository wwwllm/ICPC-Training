#include<bits/stdc++.h>
using namespace std;

int f[1000050]={0},g[1000050]={0};
int main(){
	f[1]=1;
	g[1]=1;
	f[2]=2;
	g[2]=2;
	int n;
	cin>>n;
	if(n<=1){
		cout<<f[n];
		return 0;
	}
	for(int i=3;i<=n;i++){
		f[i]=(f[i-1]+2*g[i-2]+f[i-2])%10000;
		g[i]=(f[i-1]+g[i-1])%10000;
	}
	cout<<f[n];
	return 0;
} 

