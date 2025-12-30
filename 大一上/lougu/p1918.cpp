#include<bits/stdc++.h>
#define MAXN
using namespace std;

int n,q;
map<int,int>ds;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ds[x]=i;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int ans;
		cin>>ans;
		cout<<ds[ans]<<endl;
	}
	return 0;
}
