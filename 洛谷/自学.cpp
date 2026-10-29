#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000050
long long n,p,k,m;
long long t[MAXN],q[MAXN];
int main(){
	cin>>n>>p;
	q[0]=0;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		q[i]=q[i-1]+t[i];
	}
	for(int i=1;i<=p;i++){
		cin>>k>>m;
		if(t[k]>m){
			cout<<0<<endl;
			continue;
		}
		if(q[n]-q[k-1]<m){
			cout<<n-k+1<<endl;
			continue;
		} 
		long long mid,l=k-1,r=n+1;
		while(l+1!=r){
			mid=(l+r)/2;
			if(q[mid]-q[k-1]<=m)l=mid;
			else	r=mid;
		}
		cout<<r-k<<endl;
	}
	return 0;
}
