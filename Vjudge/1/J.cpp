#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=2e5+50;
int b[maxn],ans[maxn],c[maxn],s[maxn]; 
void solve(){
	int n,a;
	cin>>n;
	int top=0;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){ 
		cin>>a;
		b[a]++;
	}
	for(int i=0;i<=n;i++)c[i]=b[i];
	ans[0]=b[0]==0?-1:0;
	if(b[0]>1)s[++top]=0;
	for(int i=1;i<=n;i++){
		if(ans[i-1]==-1){
			ans[i]=ans[i-1];
			continue;
		}
		if(b[i]!=0){
			ans[i]=ans[i-1];
			if(b[i]>1)s[++top]=i;
		}
		else{
			if(top){
				ans[i]=ans[i-1]+i-s[top];
				c[s[top]]--;
				c[i]++;
				if(c[s[top]]==1)top--;
			}else{
				ans[i]=-1;
			}
		}
	}
	cout<<b[0]<<' ';
	for(int i=1;i<=n;i++){
		if(ans[i-1]!=-1){
			cout<<ans[i-1]+b[i]<<' ';
		}else	cout<<-1<<' '; 
	}
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
