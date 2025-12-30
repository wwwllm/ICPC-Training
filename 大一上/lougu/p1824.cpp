#include<bits/stdc++.h>
using namespace std;

long long t[100050]={0};
int n,c;
bool p(int x){
	int q=1,k=1;
	for(int i=2;i<=n;i++){
		if(t[i]-t[q]>=x){
			q=i;
			k++;
		}
	}
	return k>=c;
}
int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	sort(t+1,t+1+n);
	int l=0,r=t[n],mid=(l+r)/2;
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
