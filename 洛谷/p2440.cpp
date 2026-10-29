#include<bits/stdc++.h>
using namespace std;

int t[100050]={0};
int k,n;
bool p(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=t[i]/x;
	}
	return ans>=k;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int l=0,r=100000000,mid;
	while(l+1!=r){
		mid=(l+r)/2;
		if(p(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
