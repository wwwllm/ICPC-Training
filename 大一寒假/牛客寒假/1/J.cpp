#include<bits/stdc++.h>
#define int long long
using namespace std;

/*位运算题型：
 	1.变形：a^b==gcd(a,b)-->a^gcd(a,b)==b
	2.按位去看 
*/ 
//1.a^b==gcd(a,b)-->b==a+gcd(a,b)
//2.枚举a的因子
const int maxn=2e5+50;
int a[maxn]={0},cnt[2*maxn]={0}; 
int gcd(int a,int b){
	if(b>a){
		int temp;
		temp=a;
		a=b;
		b=temp; 
	} 
	return b==0?a:gcd(b,a%b);
}
void solve(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				int x=(a[i]^j);
				if(gcd(a[i],x)==j){
					ans+=cnt[x];
				}
				if(j*j!=a[i]){
					int k=a[i]/j;
					int y=(a[i]^k);
					if(gcd(a[i],y)==k){
						ans+=cnt[y];
					}
				}
			}
		}
	}
	cout<<ans/2<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
