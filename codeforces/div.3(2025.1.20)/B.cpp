#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2005;
int f[maxn][maxn];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>f[i][j];
	vector<int> arr(m+1);
	vector<int> b(n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)arr[j]=f[i][j];
		sort(arr.begin(),arr.end());
		b[i]=arr[1];
		for(int j=2;j<=m;j++){
			if(arr[j]!=arr[j-1]+n){
				cout<<-1<<endl;
				return ;
			}
		}
	}
	map<int ,int >mp;
	for(int i=1;i<=n;i++)mp[b[i]]=i;
	for(auto ele:mp)cout<<ele.second<<' ';
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
