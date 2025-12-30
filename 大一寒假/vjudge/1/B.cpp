#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=55;
ll a[maxn];
ll b[maxn];
bool check(int n){
	for(int i=1;i<=n;i++){
		if(b[i]==0)return false;
	}
	return true;
}
void solve(){
	int n;
	cin>>n;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]>n)a[i]/=2;
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(b[i]>1){
			int t=b[i];
			for(int j=1;j<=t-1;j++){
				int x=i;
				while(x){
					if(b[x]==0){
						b[x]++;
						b[i]--;
						break;
					}
					x=x>>1;
				}
			}
		}
	}
	if(check(n))cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
