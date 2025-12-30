#include<bits/stdc++.h>
using namespace std;

int t[50050]={0};
int n,m,l;
bool p(int x){
	int q=0,num=0;
	for(int i=1;i<=n;i++){
		if(t[i]-q>=x){
			q=t[i];
			num++;
		}
	}
	if(l-q<x){
		num--;
	} 
	return num>=n-m;
}
int main(){
	cin>>l>>n>>m;
	if(n==0){
		cout<<l;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int i=0,j=l+1,mid;
	while(i+1!=j){
		mid=(i+j)/2;
		if(p(mid)){
			i=mid;
		}else{
			j=mid;
		}
	}
	cout<<i;
	return 0;
}
