#include<bits/stdc++.h>
using namespace std;

int n,m,t[25]={0},sum=0,ans=0,b[25]={0};
bool prime(int n){
	if(n==1||n==2||n==3)return true;
	if(n%2==0)return false;
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0)return false;
	}
	return true;
}
void dfs(int p,int x){
	if(x>=m){
		if(prime(sum)){
			ans++;
		}
		return ;
	}
	for(int i=p+1;i<=n;i++){
		if(b[i]==0){
			sum+=t[i];
			b[i]=1;
			dfs(i,x+1);
			sum-=t[i];
			b[i]=0;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
} 
