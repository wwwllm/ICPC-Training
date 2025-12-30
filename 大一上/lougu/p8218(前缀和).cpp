#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e5+50;
int n,m,l,r;
int arr[maxn];
signed main(){
	cin>>n;
	arr[0]=0;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		arr[i]=q+arr[i-1];
	}
	cin>>m;
	while(m--){
		cin>>l>>r;
		cout<<arr[r]-arr[l-1]<<endl;
	}
	return 0;
}
