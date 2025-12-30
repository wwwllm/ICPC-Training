#include<bits/stdc++.h>
#define int long long
using namespace std;

//优先队列 
const int maxn=1e5+50;
struct d{
	int l,r,pos;
}a[maxn]; 
bool cmp(d a,d b){
	return a.l==b.l?a.r<b.r:a.l<b.l;
}
int ans[maxn];
struct CustomCompare {
    bool operator()(d a, d b) {
        return a.r > b.r; 
    }
};
priority_queue<d,vector<d>, CustomCompare> pq;
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r,a[i].pos=i;
	sort(a+1,a+1+n,cmp);
	int j=1;
	for(int i=1;i<=n;i++){
		while(a[j].l<=i&&j<=n){
			pq.push(a[j]);
			j++;
		}
		if(pq.empty()){
			cout<<-1<<endl;
			return ;
		}
		d temp=pq.top();
		if(temp.l<=i&&temp.r>=i){
			ans[temp.pos]=i;
			pq.pop();
		}
		else{
			cout<<-1<<endl;
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
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
