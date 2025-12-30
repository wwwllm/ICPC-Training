#include<bits/stdc++.h>
using namespace std;

int t[1000050]={0};
int n,m;
bool p(int x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(t[i]>x)	sum+=t[i]-x;
	}
	if(sum>=m)return true;
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int i=1,j=400000,k=(i+j)/2,ans=0;
	while(i<=j){
		k=(i+j)/2;
		if(p(k)){
			i=k+1;
			ans=k;
		}
		else{
			j=k-1;
		}
	}
	cout<<ans;
	return 0;
}
