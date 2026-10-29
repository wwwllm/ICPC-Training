#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n,k;
long long qmax[maxn],a[maxn],qmin[maxn];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int hmax=0,tmax=0,hmin=0,tmin=0;
	for(int i=1;i<=n;i++){
		while(hmin<tmin&&qmin[hmin]+k<=i)	hmin++;
		while(hmin<tmin&&a[qmin[tmin-1]]>a[i])	tmin--;
		qmin[tmin++]=i;
		if(i>=k){
			cout<<a[qmin[hmin]]<<' ';
		}
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		while(hmax<tmax&&qmax[hmax]+k<=i)	hmax++;
		while(hmax<tmax&&a[qmax[tmax-1]]<a[i])	tmax--;
		qmax[tmax++]=i;
		if(i>=k){
			cout<<a[qmax[hmax]]<<' ';
		}
	}
	return 0;
} 
