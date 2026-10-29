#include<bits/stdc++.h>
using namespace std;

long long t[200050]={0};
int main(){
	int n;
	long long c,sum=0,b=0;
	cin>>n>>c;
	int bs,be;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	sort(t+1,t+1+n);
	for(int a=1;a<=n;a++){
		b=t[a]+c;
		bs=lower_bound(t+1,t+1+n,b)-t;
		be=upper_bound(t+1,t+1+n,b)-t;
		sum+=be-bs;
	}
	cout<<sum;
	return 0;
}
