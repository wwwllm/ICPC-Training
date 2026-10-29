#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e9,num=40000;
int a[num],top=0;
set<int>s;
void solve(){
	int n;
	cin>>n;
	int l=0,r=top+1,mid;
	while(l+1!=r){
		mid=(l+r)>>1;
		if(a[mid]>n)r=mid;
		else	l=mid;
	}
	cout<<l<<endl;
}
signed main(){
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for(int i=1;i<=num;i++){
		if(i*i<=maxn)s.insert(i*i);
		else	break;
		if(i*i*i<=maxn)s.insert(i*i*i);
	}
	set<int>::iterator it=s.begin();
	for(;it!=s.end();it++){
		a[++top]=*it;
	}
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
