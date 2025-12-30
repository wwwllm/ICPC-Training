#include<bits/stdc++.h>
using namespace std;

#define maxn 210
int t[maxn],ans[maxn];
queue<int>Q;
int main(){
	memset(ans,-1,sizeof(ans));
	int n,a,b;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	Q.push(a);
	ans[a]=0;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		int upk=k+t[k],downk=k-t[k];
		if(upk<=n&&ans[upk]==-1){
			Q.push(upk);
			ans[upk]=ans[k]+1;
		}
		if(downk>=1&&ans[downk]==-1){
			Q.push(downk);
			ans[downk]=ans[k]+1;
		}
	}
	cout<<ans[b];
	return 0;
}
