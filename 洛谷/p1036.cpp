#include<bits/stdc++.h>
using namespace std;

int x[25]={0},ans=0;
int n,k;
bool sushu(int t){
	if(t==0||t==1)return false;
	for(int i=2;i*i<t;i++){
		if(t%i==0)return false;
	}
	return true;
}
void f(int m,int sum,int s){
	if(m==k){
		if(sushu(sum))ans++;
		return ;
	}
	for(int j=s;j<=n;j++){
		f(m+1,sum+x[j],j+1);
	}
	return ;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>x[i];
	f(0,0,1);
	cout<<ans;
	return 0;
}
