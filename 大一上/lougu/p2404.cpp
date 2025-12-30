#include<bits/stdc++.h>
using namespace std;

int k;
int p[10]={0};
void dfs(int n,int m,int k){//m为上一个数 
	if(n==0){
		if(k==2)return ;
		for(int i=1;i<k;i++){
			if(i==k-1){
				cout<<p[k-1]<<endl;
				break;
			}
			cout<<p[i]<<'+';
		}
		return ;
	}
	for(int i=m;i<=n;i++){
		p[k]=i;
		dfs(n-i,i,k+1);
		p[k]=0;
	}
}
int main(){
	cin>>k;
	dfs(k,1,1);
	return 0;
}
