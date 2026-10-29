#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+50;
int a[maxn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int h=0,l;
	bool flag1=false;
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1]){
			if(h!=0&&h!=a[i]){
				cout<<h<<' '<<h<<' '<<a[i]<<' '<<a[i]<<endl;
				return;
			}else{
				h=a[i];
				l=i;
			}
			i++;
			flag1=1;
		}
	}
	if(!flag1){
		cout<<-1<<endl;
		return ;
	}
	for(int i=1;i<=n-1;i++){
		if(i==l){
			i++;
			continue;
		}
		if(i+1==l){
			if(a[l+2]-a[i]<2*h){
				cout<<h<<' '<<h<<' '<<a[i]<<' '<<a[l+2]<<endl;return ;
			}
		}
		else{
			if(a[i+1]-a[i]<2*h){cout<<h<<' '<<h<<' '<<a[i]<<' '<<a[i+1]<<endl;return ;}
		}
	}
	cout<<-1<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
