#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5+50;
int s[maxn];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+1+n);
	int l=1,r=n,ans=0;
	while(l<r){
		if(s[l]+s[r]>k)r--;
		else if(s[l]+s[r]==k){
			l++;
			ans++;
			r--;
		}else	l++;
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
