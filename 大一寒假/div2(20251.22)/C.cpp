#include<bits/stdc++.h>
using namespace std;

struct mp{
	int k,p;
};
const int maxn=2e5+50;
mp d[maxn];
int t[maxn][2];
bool cmp(mp a,mp b){
	return a.k>b.k;
}
void solve(){
	int n;
	cin>>n;
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)d[i].p=i;
	for(int i=1;i<=n-1;i++){
		int l,r;
		cin>>l>>r;
		t[i][0]=l;
		t[i][1]=r;
		d[l].k++;
		d[r].k++;
	}
	if(n==2){
		cout<<0<<endl;
		return ;
	}
	sort(d+1,d+1+n,cmp);
	if(d[2].k>1){
		for(int i=1;i<=n;i++){
			if((t[i][0]==d[1].p&&t[i][1]==d[2].p)&&(t[i][1]==d[1].p&&t[i][0]==d[2].p))
			{
				cout<<d[1].k-2+d[2].k<<endl;
				return ;
			}
		}
		cout<<d[1].k-1+d[2].k<<endl;
	}
	else	cout<<d[1].k-1<<endl;
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
