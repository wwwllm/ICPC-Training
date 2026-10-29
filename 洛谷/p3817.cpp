#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t[100050]={0};
int main(){
	ll n,x,sum=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	if(t[1]>x){
		sum+=t[1]-x;
		t[1]=x;
	}
	for(int i=2;i<=n;i++){
		if(t[i]+t[i-1]>x){
			sum+=t[i]+t[i-1]-x;
			t[i]=x-t[i-1];
		}
	}
	cout<<sum;
	return 0;
}
