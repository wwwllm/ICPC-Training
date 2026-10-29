#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000050
int n,m,x,pri[10000];
typedef long long ll;
bool a[MAXN];
int Eratothenes_sieve(int n){
	int cnt=0;
	for(int i=2;i*i<=n;i++){
		if(!a[i]){
			for(int j=i<<1;j<=n;j+=i){
				a[j]=1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(!a[i]){
			pri[cnt++]=i;
		}
	}
	return cnt;	 
}
int main(){
	int cnt=Eratothenes_sieve(50000);
	ll l,r;
	cin>>l>>r;
	memset(a,0,sizeof(a));
	for(int i=0;i<cnt;i++){
		for(ll j=max(2ll,(l-1)/pri[i]+1)*pri[i];j<=r;j+=pri[i]){
			a[j-l]=1;
		}
	}
	int ans=0;
	for(ll i=l;i<=r;i++){
		if(a[i-l]==0)ans++;
	}
	if(l==1)ans--;
	cout<<ans;
	return 0;
} 
