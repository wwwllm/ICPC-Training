//求极差不超过k的最长子序列长度 
#include<bits/stdc++.h>
#define maxn 50050
using namespace std;

int n,k,a[maxn],ans=0;
int qmax[maxn],hmax=0,tmax=0;
int qmin[maxn],hmin=0,tmin=0;
bool check(int r){
	int maxi=hmax<tmax?max(a[qmax[hmax]],a[r]):a[r];
	int mini=hmin<tmin?min(a[qmin[hmin]],a[r]):a[r];
	return maxi-mini<k;
}
void push(int r){
	while(hmax<tmax&&a[qmax[tmax-1]]<a[r])tmax--;
	qmax[tmax++]=r;
	while(hmin<tmin&&a[qmin[tmin-1]]>a[r])tmin--;
	qmin[tmin++]=r;
}
void pop(int l){
	while(hmax<tmax&&qmax[hmax]==l)hmax++;
	while(hmin<tmin&&qmin[hmin]==l)hmin++;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1,r=1;l<=n;l++){
		while(r<n&&check(r))push(r++);
		ans=max(ans,r-l);
		pop(l);
	} 
	cout<<ans;
	return 0;
} 
