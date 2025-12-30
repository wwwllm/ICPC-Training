#include<bits/stdc++.h>
using namespace std;

const int maxn=5e6+50;
int n,p;
int a[maxn],b[maxn],ans=100000;
int main(){
	cin>>n>>p;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	while(p--){
		int l,r,z;
		cin>>l>>r>>z;
		b[l]+=z;
		b[r+1]-=z;
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		ans=min(b[i],ans);
	}
	cout<<ans;
	return 0;
}

