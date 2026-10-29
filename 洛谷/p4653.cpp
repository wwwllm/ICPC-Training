#include<bits/stdc++.h>
using namespace std;

const int maxn=100050;
int n;
double a[maxn],b[maxn];
bool cmp(double a,double b){
	return a>b;
}
double ans=0.0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=2;i<=n;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	for(int i=1,j=1;i<=n&&j<=n;){
		if(a[i]>b[j]){
			ans=max(b[j]-i-j,ans);
			j++;
		}
		else{
			ans=max(a[i]-i-j,ans);
			i++;
		}
	}
	cout<<fixed<<setprecision(4)<<ans;
	return 0;
}
