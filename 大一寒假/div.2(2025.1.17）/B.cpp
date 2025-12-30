#include<bits/stdc++.h>
using namespace std;
 

/*struct shu{
	int num=0,t=0;
};
const int maxn=1050;
bool cmp(shu a,shu b){
	if(a.t==b.t)return a.num>b.num;
	return a.t<b.t;
}
void solve(){
	int n;
	cin>>n;
	shu ans[maxn];
	bool flag=true;
	for(int i=1;i<=n;i++){
		ans[i].num=i;
		for(int j=1;j<=n;j++){
			char c;
			cin>>c;
			ans[i].t+=c-'0';
		}
	}
	sort(ans+1,ans+1+n,cmp);
	for(int i=1;i<=n;i++)cout<<ans[i].num<<' ';
	cout<<endl;
}*/
//Ë¼Â·´íÁË
const int maxn=1050;
string s[maxn];
int ans[maxn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		int q=0;
		for(int j=0;j<n;j++){
			if((i<j+1&&s[i][j]=='0')||(i>j+1&&s[i][j]=='1')) q++;
		}
		ans[q++]=i;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
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
